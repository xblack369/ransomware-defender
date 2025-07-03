rule Ransomware_Indicator {
    meta:
        description = "র্যানসমওয়্যার সনাক্তকরণ"
        author = "আপনার নাম"
    strings:
        $str1 = "encrypt" nocase
        $str2 = "decrypt" nocase
        $str3 = "bitcoin" nocase
        $str4 = "ransom" nocase
        $str5 = "GANDCRAB"
        $str6 = "WannaCry"
    condition:
        any of them
}