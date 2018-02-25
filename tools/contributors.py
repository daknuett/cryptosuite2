import docopt, yaml, sys

usage = \
'''
Usage: 
        contributors.py print FILE [--quiet]
        contributors.py create FILE RST

Options:
        --quiet                do not print to stdout 

'''

if( __name__ == "__main__"):
	args = docopt.docopt(usage)
	
	if(args["print"]):
		try:
			f = open(args["FILE"])
		except Exception as e:
			print(e, file = sys.stdout)
			sys.exit(1)

		try:
			data = yaml.load(f)
		except Exception as e:
			print(e, file = sys.stdout)
			sys.exit(1)

		for contributor in data:
			try:
				string = "{name} (mailto:{email})".format(**contributor)
				contributions = "".join(["\t[{year}] {descr}\n".format(**c) for c in contributor["contributions"]])
			except Exception as e:
				print(e, file = sys.stdout)
				print("Dataset was:", file = sys.stdout)
				print(contributor, file = sys.stdout)
				sys.exit(1)
			if(not args["--quiet"]):
				print(string)
				print(contributions)

		sys.exit(0)

	if(args["create"]):
		try:
			f = open(args["FILE"])
		except Exception as e:
			print(e, file = sys.stdout)
			sys.exit(1)

		try:
			data = yaml.load(f)
		except Exception as e:
			print(e, file = sys.stdout)
			sys.exit(1)
		

		try:
			fout = open(args["RST"], "w")
		except Exception as e:
			print(e, file = sys.stdout)
			sys.exit(1)

		heading = "Contributors"
		print(heading, file = fout)
		print("*" * len(heading), file = fout)
		print("\n\n", file = fout)
		
		for contributor in data:
			print("**{name}** \n\n\t `{email} <mailto:{email}>`_".format(**contributor), file = fout)
			print(file = fout)
			for contribution in contributor["contributions"]:
				print("\t- *{year}* {descr}".format(**contribution), file = fout)

			
