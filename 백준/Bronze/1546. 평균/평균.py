the_number_of_subjects = int(input())
scores = list(map(int, input().split()))
highest_score = max(scores)
new_scores = [score / highest_score * 100 for score in scores]
new_average = sum(new_scores) / the_number_of_subjects
print(new_average)