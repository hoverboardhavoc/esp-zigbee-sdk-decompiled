/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> metering_desc.o -> zcl_metering_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zcl_metering_cluster_get_attr_properties(int param_1,uint param_2,char *param_3,char *param_4)

{
  uint uVar1;
  
  if (param_3 == (char *)0x0) {
    return 2;
  }
  if (param_4 == (char *)0x0) {
    return 2;
  }
  if ((param_1 - 1U & 0xffff) < 2) {
    if (param_1 != 1) {
      if (7 < param_2) {
        return 6;
      }
      *param_4 = '\x01';
      *param_3 = '\x1b';
      return 0;
    }
  }
  else {
    param_4 = "cluster_role == 0x01U || cluster_role == 0x02U";
    param_3 = "zcl_metering_cluster_get_attr_properties";
    param_2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/metering_desc.c"
                            ,0x19);
  }
  if (param_2 < 0x45c) {
    if (0x43f < param_2) {
_L0:
      *param_4 = '\x01';
      *param_3 = '#';
      return 0;
    }
    if (param_2 == 0x204) {
      *param_4 = '\x01';
      *param_3 = '\x1f';
      return 0;
    }
    if (0x204 < param_2) {
      if (param_2 < 0x315) {
        if (param_2 < 0x303) {
          if (param_2 == 0x206) {
_L0:
            *param_4 = '\x01';
            *param_3 = 'A';
            return 0;
          }
          if (param_2 < 0x207) {
            if (param_2 != 0x205) {
              return 6;
            }
            goto _L0;
          }
          if (param_2 != 0x300) {
            if (0x300 < param_2) {
              if (1 < (param_2 - 0x301 & 0xffff)) {
                return 6;
              }
              goto _L0;
            }
            if (param_2 != 0x207) {
              return 6;
            }
          }
        }
        else {
          uVar1 = 1 << (param_2 - 0x303 & 0x1f);
          if ((uVar1 & 0x3058f) != 0) {
_L0:
            *param_4 = '\x01';
            *param_3 = '\x18';
            return 0;
          }
          if ((uVar1 >> 4 & 0x783) != 0) goto _L0;
          if ((uVar1 >> 6 & 0x209) == 0) {
            return 6;
          }
        }
        goto _L0;
      }
      if (param_2 < 0x409) {
        if (param_2 < 0x407) {
          if (param_2 == 0x400) goto _L0;
          if (param_2 < 0x400) {
            return 6;
          }
          if (0x404 < param_2) {
            if (1 < (param_2 - 0x405 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
          if (param_2 < 0x401) {
            return 6;
          }
        }
      }
      else {
        if (param_2 < 0x417) {
          if (param_2 < 0x40d) {
            if (3 < (param_2 - 0x409 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
_L0:
          *param_4 = '\x01';
          *param_3 = '*';
          return 0;
        }
        if (param_2 < 0x42e) {
          if (param_2 < 0x420) {
            return 6;
          }
        }
        else if (0xb < (param_2 - 0x430 & 0xffff)) {
          return 6;
        }
      }
_L0:
      *param_4 = '\x01';
      *param_3 = '\"';
      return 0;
    }
    if (param_2 != 0xf) {
      if (param_2 < 0x10) {
        if (param_2 == 6) {
          *param_4 = '\x01';
          *param_3 = '(';
          return 0;
        }
        if (param_2 < 7) {
          if (4 < param_2) {
            if (param_2 != 5) {
              return 6;
            }
            goto _L0;
          }
        }
        else {
          if (param_2 < 0xc) {
            if (param_2 < 10) {
              if (2 < (param_2 - 7 & 0xffff)) {
                return 6;
              }
              goto _L0;
            }
            goto _L0;
          }
          if (param_2 == 0xd) goto _L0;
          if (param_2 == 0xe) goto _L0;
          if (param_2 != 0xc) {
            return 6;
          }
        }
      }
      else if (param_2 != 0x1f) {
        if (param_2 < 0x20) {
          if (param_2 < 0x17) {
            if (0x14 < param_2) goto _L0;
            if (param_2 == 0x13) goto _L0;
            if (param_2 < 0x14) {
              if (1 < (param_2 - 0x11 & 0xffff)) {
                return 6;
              }
              goto _L0;
            }
            if (param_2 != 0x14) {
              return 6;
            }
          }
          else {
            if (param_2 < 0x1c) {
              if (param_2 < 0x17) {
                return 6;
              }
              goto _L0;
            }
            if (param_2 < 0x1e) {
              if (param_2 < 0x1c) {
                return 6;
              }
              goto _L0;
            }
            if (param_2 != 0x1e) {
              return 6;
            }
          }
          goto _L0;
        }
        if (param_2 != 0x1fe) {
          if (0x1fe < param_2) {
            if (param_2 != 0x201) {
              if (param_2 < 0x202) {
                if (param_2 != 0x200) {
                  return 6;
                }
                goto _L0;
              }
              if (1 < (param_2 - 0x202 & 0xffff)) {
                return 6;
              }
              goto _L0;
            }
            goto _L0;
          }
          if (param_2 == 0x22) goto _L0;
          if (param_2 < 0x23) {
            if (1 < (param_2 - 0x20 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
          if (param_2 < 0x160) {
            if (param_2 < 0x100) {
              return 6;
            }
          }
          else if (param_2 != 0x1fc) {
            return 6;
          }
        }
      }
    }
_L0:
    *param_4 = '\x01';
    *param_3 = '%';
    return 0;
  }
  if (param_2 != 0x807) {
    if (param_2 < 0x808) {
      if (param_2 == 0x801) {
        *param_4 = '\x03';
        *param_3 = '\x1b';
        return 0;
      }
      if (0x801 < param_2) {
        if (0x805 < param_2) {
          if (param_2 != 0x806) {
            return 6;
          }
          *param_4 = '\x03';
          *param_3 = '\x1d';
          return 0;
        }
        if (param_2 < 0x802) {
          return 6;
        }
        goto _L0;
      }
      if (param_2 != 0x605) {
        if (param_2 < 0x606) {
          if (param_2 < 0x602) {
            if (0x5ff < param_2) goto _L0;
            if (param_2 == 0x45c) goto _L0;
            if (param_2 != 0x500) {
              return 6;
            }
          }
          else {
            if (0x603 < param_2) {
              if (param_2 != 0x604) {
                return 6;
              }
_L0:
              *param_4 = '\x01';
              *param_3 = '!';
              return 0;
            }
            if (param_2 < 0x602) {
              return 6;
            }
          }
_L0:
          *param_4 = '\x01';
          *param_3 = ' ';
          return 0;
        }
        if (param_2 == 0x800) goto _L0;
        if (0x800 < param_2) {
          return 6;
        }
        if (0x609 < param_2) {
          if (0xff < (param_2 - 0x700 & 0xffff)) {
            return 6;
          }
          goto _L0;
        }
        if (param_2 < 0x607) {
          if (param_2 != 0x606) {
            return 6;
          }
          goto _L0;
        }
      }
    }
    else {
      if (0xb15 < param_2) {
        if (param_2 < 0xc0d) {
          if (0xc08 < param_2) goto _L0;
          if (param_2 < 0xc05) {
            if (param_2 < 0xc01) {
              if (param_2 != 0xc00) {
                return 6;
              }
              goto _L0;
            }
          }
          else {
            if (param_2 < 0xc07) {
              if (param_2 < 0xc05) {
                return 6;
              }
              goto _L0;
            }
            if (1 < (param_2 - 0xc07 & 0xffff)) {
              return 6;
            }
          }
        }
        else if (param_2 < 0xc2e) {
          if (param_2 < 0xc20) {
            if (3 < (param_2 - 0xc0d & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
        }
        else {
          if (0xc3b < param_2) {
            if (0x1b < (param_2 - 0xc40 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
          if (param_2 < 0xc30) {
            return 6;
          }
        }
        goto _L0;
      }
      if (param_2 < 0xb01) {
        if (param_2 < 0xa15) {
          if (param_2 < 0xa00) {
            if (0xff < (param_2 - 0x900 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
          uVar1 = 1 << (param_2 - 0xa00 & 0x1f);
          if ((uVar1 & 0x50005) != 0) goto _L0;
          if ((uVar1 & 0xa000a) == 0) {
            if ((uVar1 & 0x100010) == 0) {
              return 6;
            }
            goto _L0;
          }
        }
        else if (param_2 != 0xb00) {
          return 6;
        }
_L0:
        *param_4 = '\x01';
        *param_3 = -0x1e;
        return 0;
      }
      uVar1 = 1 << (param_2 - 0xb01 & 0x1f);
      if ((uVar1 >> 0xf & 0x2d) != 0) goto _L0;
      if ((uVar1 & 0x10001) == 0) {
        if (-1 < (int)(uVar1 << 0xc)) {
          return 6;
        }
        goto _L0;
      }
    }
_L0:
    *param_4 = '\x01';
    *param_3 = '0';
    return 0;
  }
_L0:
  *param_4 = '\x03';
  *param_3 = '\x19';
  return 0;
}

