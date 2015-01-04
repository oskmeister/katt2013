import sys

def is_int(arg):
    try:
        int(arg)
        return True
    except:
        return False


def main():
    if "ignore" in sys.argv:
        print "AC 0"
    elif "sum" in sys.argv:
        error = None
        total_score = 0
        for line in sys.stdin.readlines():
            verdict, score = line.split()
            if verdict != "AC":
                if not error:
                    error = verdict
            total_score += float(score)
        if not total_score and error:
            print "%s 0" % error
        else:
            print "AC %f" % (total_score)
    elif "pass" in sys.argv:
        error = None
        total_score = 0
        for line in sys.stdin.readlines():
            verdict, score = line.split()
            if verdict != "AC":
                if not error:
                    error = verdict
            total_score += float(score)
        if not total_score and error:
            print "%s 0" % error
        else:
            print "AC %f" % (10 * total_score)
    else:
        for line in sys.stdin.readlines():
            print line

main()
