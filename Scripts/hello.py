from flask import Flask, render_template,request, abort, jsonify, send_from_directory, request, send_file
import os
app = Flask(__name__)
UPLOAD_DIRECTORY = "D:\games_data"
@app.route('/')
def index():
	
	directory_contents = [name for name in os.listdir(UPLOAD_DIRECTORY) ]


	return render_template('index.html',directory_contents = directory_contents,cur_dir=UPLOAD_DIRECTORY)


@app.route("/browse/<path:path>")
def browse_directory(path):
	files = []
	folders = []
	for item in os.listdir(path):
		if os.path.isdir(path + '/' + item) == True:
			folders.append(item)
		else:
			files.append(item)

	return render_template('browse.html' , cur_dir = path , folders = folders , files = files)

	



@app.route("/download_file/<path:path>")
def get_file(path):
    return send_file( path, as_attachment=True)

@app .route("/upload", methods=["POST"])
def post_file():
    
	f = request.files['fileToUpload']
	f.save(UPLOAD_DIRECTORY + '/'+ f.filename)
	return 'file uploaded successfully'