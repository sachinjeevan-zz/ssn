attempts = Attempt.where(course_id: nil).all
attempts.each do |attempt|
    begin
        contest_id = attempt.contest_id
        contest = Contest.where(id: contest_id).first
        course_id = contest.sub_modules.unit.course[:id]
        attempt[:course_id] = course_id
        attempt.save
    rescue

    end
end