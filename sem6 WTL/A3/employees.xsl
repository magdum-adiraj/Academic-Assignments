<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html> 
<body>
  <h2>Employees</h2>
  <table border="1">
    <tr bgcolor="#F0F0F0">
      <th style="text-align:left">EID</th>
      <th style="text-align:left">First Name</th>
      <th style="text-align:left">Last Name</th>
      <th style="text-align:left">Salary</th>
      <th style="text-align:left">Company</th>
      <th style="text-align:left">Age</th>
    </tr>
    <xsl:for-each select="employees/employee">
    <tr>
      <td><xsl:value-of select="eid"/></td>
      <td><xsl:value-of select="firstname"/></td>
      <td><xsl:value-of select="lastname"/></td>
      <td><xsl:value-of select="salary"/></td>
      <td><xsl:value-of select="city"/></td>
      <td><xsl:value-of select="age"/></td>
    </tr>
    </xsl:for-each>
  </table>
</body>
</html>
</xsl:template>
</xsl:stylesheet>

