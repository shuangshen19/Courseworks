# HW: Recommendation System II 

2018/11/06

## User Requirements:
* Functional Requirements:
  1. Students and recommendation letter writers must apply to use this system. Academic institutions will intend to rent
  Zhao number and password unique to this school
  2. Students must provide the name, title, and e-mail address of the writer of each recommendation letter
  3. The recommendation letter writer should finish uploading the recommendation letter within the deadline
  4. The student will be able to check whether the recommendation letter in the project he applied for has been uploaded
  5. The system will record the information of applicants and recommenders on this platform for the organization to do
  Integrity verification
  6. All materials are uploaded in pdf format
   
* Non-functional Requirements:
  1. All three users can view the application information, recommendation letter, and student information in their account at any time
  2. All users have their own unique account and password
  3. Students cannot view the content of the letter

## System Requirements:
* Functional Requirements:
  * 1.1 When making an application, students will get a link to fill in the recommendation letter for each different application according to the department and category of each school or other institution.
  * 1.2 The student will get a set of accounts dedicated to him for uploading his autobiography, reading plan and other materials
  * 1.3 The recommender will create a set of accounts belonging to him, verify with work status and write recommendation letters
  * 1.4 Academic institutions will have their own account secrets to view student application materials and recommendation letters
  * 2.1 The system will send this link to the mailbox of the writer of the recommendation letter filled out by the student
  * 2.2 The system will attach the deadline for the recommendation letter of this school or organization to the letter so that the writer can complete it within the deadline
  * 2.3 Two days before the deadline, the recommendation letter writers and their applicants who have not yet been filled out will be notified again to protect the rights and interests of both parties
  * 3.1 The writer of the recommendation letter must verify the received link with his account on the platform
  * 4.1 The system will display in the student's photo number whether the recommendation letter has been uploaded
  * 5.1 The system will initially check whether the content of the applicant's information is roughly consistent with the content written by the recommender, and give a preliminary integrity score for the institution's reference
  * 5.2 The agency will give another integrity score after the review, and the average of the two will be recorded in the account of the applicant and the recommender so that the agency can view its total integrity score for the next recommendation.
  * 6.1 The system will only accept pdf files, other formats will not be used by users.
   
* Non-functional Requirements:
  * 1.1 Users can view the data at any time, but the data can be modified only within the standard time of the academic exchange
  * 1.2 Applicants will be able to log in to the system at any time to check that the recommendation letter writer has not yet or has completed uploading the recommendation letter and related matters
  * 2.1 All users must use their own unique account and password for identity verification
  * 3.1 Applicants will only be able to judge whether the recommendation letter is uploaded or not, and the content of the recommendation letter will be encrypted by the system and can only be viewed by the applying school or institution

## Reference:
* http://mropengate.blogspot.com/2015/11/software-engineering-introduction-to.html
* https://medium.com/omarelgabrys-blog/requirements-engineering-elicitation-analysis-part-5-2dd9cffafae8
* http://www.inf.ed.ac.uk/teaching/courses/cs2/LectureNotes/CS2Ah/SoftEng/se02.pdf
