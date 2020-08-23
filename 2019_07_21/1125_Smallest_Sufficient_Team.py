class Solution(object):
    def smallestSufficientTeam(self, req_skills, people):
        """
        :type req_skills: List[str]
        :type people: List[List[str]]
        :rtype: List[int]
        """
        n, m=len(req_skills),len(people)
        skill_index_dict={v: i for i, v in enumerate(req_skills)}
        dp={0:[]}
        for i, p in enumerate(people):
            his_skill_set=0
            for his_skill in p:
                if his_skill in skill_index_dict:
                    his_skill_set |= 1<<skill_index_dict[his_skill]
            for skill, need_people in dp.items():
                with_this_people= skill | his_skill_set
                if with_this_people==skill:
                    continue
                if with_this_people not in dp or len(dp[with_this_people])>len(need_people)+1:
                    dp[with_this_people]=need_people + [i]
        return dp[(1<<n)-1]
