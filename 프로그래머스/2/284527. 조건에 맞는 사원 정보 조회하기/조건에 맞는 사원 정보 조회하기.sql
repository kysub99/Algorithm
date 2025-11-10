-- 코드를 작성해주세요
select sum(hr.score) as score, he.emp_no, he.emp_name, he.position, he.email
from hr_grade hr
join hr_employees he
    on hr.emp_no = he.emp_no
join hr_department hd
    on he.dept_id = hd.dept_id
group by he.emp_no, he.emp_name, he.position, he.email
having sum(hr.score) = (
    select max(total_score)
    from (
        select emp_no, sum(score) as total_score
        from hr_grade
        group by emp_no
    ) t
)