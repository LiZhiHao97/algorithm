/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
function versionParts(version) {
  return version.split('.').map(item => parseInt(item))
}
function compareVersion(version1, version2) {
  const v1 = versionParts(version1)
  const v2 = versionParts(version2)
  while(v1.length || v2.length) {
    let a = v1.length ? v1.shift() : 0
    let b = v2.length ? v2.shift() : 0

    if (a > b) {
      return 1
    } else if (a < b) {
      return -1
    }
  }

  return 0
}

const version1 = '1.0.1'
const version2 = '1.2'

console.log(compareVersion(version1, version2))