SELECT s1.student_id, s1.student_name, s2.subject_name, 
COUNT(e.subject_name) AS attended_exams
FROM Students AS s1
JOIN Subjects AS s2
LEFT JOIN Examinations AS e
ON s1.student_id = e.student_id AND s2.subject_name = e.subject_name
GROUP BY s1.student_id, s2.subject_name
ORDER BY student_id ASC, subject_name ASC

-- 1. I had given e.subject_name but all the subjects need to be mentioned irrespective of no.
-- 2. Used SUM
-- 4. Did JOIN Examinations.
-- 5. Used Join 
-- 6. Didn't applied s2.subject_name = e.subject_name
-- 7. Didn't grouped s2.subject_name.