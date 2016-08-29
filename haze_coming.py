#!/usr/bin/python
import pymongo
import sys
from datetime import datetime


client = pymongo.MongoClient("ds161475.mlab.com",61475)
db=client["p-fire"]
db.authenticate('purple-daddy', 'pdaddy')
id_back=db.purplegarage.insert_one({"value":int(sys.argv[1]),"time":datetime.now()})
print id_back.inserted_id
print sys.argv[1]
