/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> electrical_measurement_desc.o -> zcl_electrical_measurement_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zcl_electrical_measurement_cluster_get_attr_properties
          (int param_1,uint param_2,char *param_3,char *param_4)

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
      return 6;
    }
  }
  else {
    param_4 = "cluster_role == 0x01U || cluster_role == 0x02U";
    param_3 = "zcl_electrical_measurement_cluster_get_attr_properties";
    param_2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/electrical_measurement_desc.c"
                            ,0x19);
  }
  if (0x517 < param_2) {
    if (param_2 < 0x80b) {
      if (0x806 < param_2) {
        *param_4 = '\x03';
        *param_3 = ')';
        return 0;
      }
      if (param_2 < 0x703) {
        if (param_2 < 0x701) {
          if (0x605 < param_2) {
            if (param_2 == 0x700) {
              *param_4 = '\x03';
              *param_3 = '\x18';
              return 0;
            }
            return 6;
          }
          if (param_2 < 0x600) {
            return 6;
          }
          goto _L0;
        }
      }
      else {
        if (param_2 == 0x800) {
          *param_4 = '\x03';
          *param_3 = '\x19';
          return 0;
        }
        if (param_2 < 0x800) {
          return 6;
        }
        if (5 < (param_2 - 0x801 & 0xffff)) {
          return 6;
        }
      }
_L0:
      *param_4 = '\x01';
      *param_3 = ')';
      return 0;
    }
    if (param_2 == 0xa01) goto _L0;
    if (param_2 < 0xa02) {
      if (param_2 != 0x90e) {
        if (param_2 < 0x90f) {
          if (param_2 != 0x908) {
            if (0x908 < param_2) {
              if (param_2 == 0x90b) goto _L0;
              if (0x90b < param_2) {
                if (1 < (param_2 - 0x90c & 0xffff)) {
                  return 6;
                }
                goto _L0;
              }
              if (1 < (param_2 - 0x909 & 0xffff)) {
                return 6;
              }
              goto _L0;
            }
            if (param_2 != 0x905) {
              if (0x905 < param_2) {
                if (1 < (param_2 - 0x906 & 0xffff)) {
                  return 6;
                }
                goto _L0;
              }
              if (param_2 != 0x901) {
                if (param_2 < 0x901) {
                  return 6;
                }
                if (1 < (param_2 - 0x902 & 0xffff)) {
                  return 6;
                }
                goto _L0;
              }
            }
          }
        }
        else {
          if (param_2 == 0x910) {
_L0:
            *param_4 = '\x01';
            *param_3 = '(';
            return 0;
          }
          if (0x910 < param_2) {
            if (6 < (param_2 - 0x911 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
          if (param_2 != 0x90f) {
            return 6;
          }
        }
        goto _L0;
      }
    }
    else if (param_2 != 0xa0e) {
      if (0xa0e < param_2) {
        if (param_2 == 0xa10) goto _L0;
        if (0xa10 < param_2) {
          if (6 < (param_2 - 0xa11 & 0xffff)) {
            return 6;
          }
          goto _L0;
        }
        if (param_2 != 0xa0f) {
          return 6;
        }
        goto _L0;
      }
      if (param_2 < 0xa0b) {
        if (0xa08 < param_2) goto _L0;
        if (param_2 < 0xa08) {
          if (0xa05 < param_2) goto _L0;
          if (param_2 < 0xa04) {
            if (param_2 < 0xa02) {
              return 6;
            }
            goto _L0;
          }
          if (param_2 != 0xa05) {
            return 6;
          }
        }
        else if (param_2 != 0xa08) {
          return 6;
        }
        goto _L0;
      }
      if (param_2 != 0xa0b) {
        if (param_2 < 0xa0b) {
          return 6;
        }
        if (1 < (param_2 - 0xa0c & 0xffff)) {
          return 6;
        }
        goto _L0;
      }
    }
    goto _L0;
  }
  if (0x510 < param_2) {
_L0:
    *param_4 = '\x03';
    *param_3 = '!';
    return 0;
  }
  if (param_2 == 0x306) {
_L0:
    *param_4 = '\x05';
    *param_3 = '#';
    return 0;
  }
  if (param_2 < 0x307) {
    if (0x108 < param_2) {
      if (0x305 < param_2) {
        return 6;
      }
      if (0x303 < param_2) {
        *param_4 = '\x05';
        *param_3 = '+';
        return 0;
      }
      if (param_2 < 0x303) {
        if (0x300 < param_2) goto _L0;
        if (param_2 < 0x206) {
          if (param_2 < 0x200) {
            return 6;
          }
        }
        else if (param_2 != 0x300) {
          return 6;
        }
      }
      else if (param_2 != 0x303) {
        return 6;
      }
      goto _L0;
    }
    if (param_2 < 0x100) {
      if (param_2 == 0) {
        *param_4 = '\x01';
        *param_3 = '\x1b';
        return 0;
      }
      return 6;
    }
    uVar1 = 1 << (param_2 - 0x100 & 0x1f);
    if ((uVar1 & 0x1b6) != 0) goto _L0;
    if ((uVar1 & 0x49) == 0) {
      return 6;
    }
  }
  else if (param_2 < 0x406) {
    if (0x403 < param_2) {
      *param_4 = '\x05';
      *param_3 = '(';
      return 0;
    }
    if (0x403 < param_2) {
      return 6;
    }
    if (0x401 < param_2) goto _L0;
    if (0x312 < param_2) {
      if (1 < (param_2 - 0x400 & 0xffff)) {
        return 6;
      }
      goto _L0;
    }
    if (param_2 < 0x307) {
      return 6;
    }
  }
  else if (param_2 != 0x50b) {
    if (param_2 < 0x50c) {
      if (param_2 < 0x508) {
        if (0x505 < param_2) {
_L0:
          *param_4 = '\x01';
          *param_3 = '!';
          return 0;
        }
        if (param_2 < 0x504) {
          if (0x501 < param_2) goto _L0;
          if (param_2 != 0x501) {
            return 6;
          }
        }
        else if (param_2 != 0x505) {
          return 6;
        }
      }
      else if (param_2 != 0x508) {
        if (param_2 < 0x508) {
          return 6;
        }
        if (1 < (param_2 - 0x509 & 0xffff)) {
          return 6;
        }
        goto _L0;
      }
_L0:
      *param_4 = '\x05';
      *param_3 = '!';
      return 0;
    }
    if (param_2 == 0x510) goto _L0;
    if (0x510 < param_2) {
      return 6;
    }
    if (param_2 != 0x50e) {
      if (param_2 < 0x50f) {
        if (1 < (param_2 - 0x50c & 0xffff)) {
          return 6;
        }
        goto _L0;
      }
      if (param_2 != 0x50f) {
        return 6;
      }
      goto _L0;
    }
  }
_L0:
  *param_4 = '\x05';
  *param_3 = ')';
  return 0;
}

