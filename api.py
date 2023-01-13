import mysql.connector
import sys

#GET THE DATA FROM THE C PROGRAM-----------------------------------------
func = sys.argv[1]
#------------------------------------------------------------------------

#CONNECT TO MYSQL--------------------------------------------------------
mydb = mysql.connector.connect(
  host="test.mellob.co",
  user="YOUR_DB_USERNAME",
  password="YOUR_DB_PASSWORD",
  database="ticket_management_pps"
)
db = mydb.cursor()
#------------------------------------------------------------------------

#CHECK THE FUNCTION------------------------------------------------------
if func == "get_movies":
    print("Movie ID\t \tMovie Name\t \t \tAvailable Tickets\n")
    query = "SELECT * FROM `movies`"
    db.execute(query)
    for x in db:
        print(str(x[0])+"\t \t \t"+x[2]+"\t \t"+str(x[1]))


if func == "book_movie":
    #GET SOME DATA----------------------------------------------------------------------------------
    username = input("Please enter your username/customer_id (MAX_LIMIT=50): ")
    movie_id = input("Please enter Movie ID: ")
    tickets_booked_cancelled = input("Please input number of tickets: ")
    #-----------------------------------------------------------------------------------------------
    query = "INSERT INTO `booked_tickets` (username, tickets_booked, movie_id) VALUE (%s, %s, %s)"
    values = (username, tickets_booked_cancelled, movie_id)
    db.execute(query, values)
    mydb.commit()

    #UPDATING THE AVAILABLE NUMBER OF TICKETS-------------------------------------------------------
    query = "SELECT * FROM `movies` WHERE id = "+str(movie_id)
    db.execute(query)
    for x in db:
        available_tickets = x[1]
    query = "UPDATE `movies` SET `available_tickets` = '"+str(available_tickets-int(tickets_booked_cancelled))+"' WHERE `movies`.`id` = "+str(movie_id)
    #net = available_tickets-int(tickets_booked_cancelled)
    db.execute(query)
    mydb.commit()
    #-----------------------------------------------------------------------------------------------
    

if func == "cancel_movie":
    #GET SOME DATA----------------------------------------------------------------------------------
    username = input("Please enter your username/customer_id (MAX_LIMIT=50): ")
    movie_id = input("Please enter Movie ID: ")
    tickets_booked_cancelled = input("Please input number of tickets: ")
    #-----------------------------------------------------------------------------------------------
    query = "INSERT INTO `cancelled_tickets` (username, tickets_booked, movie_id) VALUE (%s, %s, %s)"
    values = (username, tickets_booked_cancelled, movie_id)
    db.execute(query, values)
    mydb.commit()

    #UPDATING THE AVAILABLE NUMBER OF TICKETS-------------------------------------------------------
    query = "SELECT * FROM `movies` WHERE id = "+str(movie_id)
    db.execute(query)
    for x in db:
        available_tickets = x[1]
    query = "UPDATE `movies` SET `available_tickets` = '"+str(available_tickets+int(tickets_booked_cancelled))+"' WHERE `movies`.`id` = "+str(movie_id)
    #net = available_tickets-int(tickets_booked_cancelled)
    db.execute(query)
    mydb.commit()
    #-----------------------------------------------------------------------------------------------





#query = "INSERT INTO `movies` (available_tickets, movie_name) VALUE (%s, %s)"
#values = ("69", "Avatar: The way of waters")
#query = "SELECT * FROM `movies`"
#db.execute(query, values)
#mydb.commit()
#print(db)
