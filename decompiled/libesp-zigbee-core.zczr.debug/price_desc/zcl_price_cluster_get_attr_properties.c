/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> price_desc.o -> zcl_price_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zcl_price_cluster_get_attr_properties(int param_1,uint param_2,char *param_3,char *param_4)

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
      if (param_2 < 2) {
        *param_4 = '\x03';
        *param_3 = ' ';
        return 0;
      }
      if (param_2 == 2) {
        *param_4 = '\x01';
        *param_3 = '0';
        return 0;
      }
      return 6;
    }
  }
  else {
    param_4 = "cluster_role == 0x01U || cluster_role == 0x02U";
    param_3 = "zcl_price_cluster_get_attr_properties";
    param_2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/price_desc.c"
                            ,0x16);
  }
  if (param_2 == 0x621) goto _L0;
  if (param_2 < 0x622) {
    if (param_2 == 0x204) {
_L0:
      *param_4 = '\x01';
      *param_3 = '\x18';
      return 0;
    }
    if (0x204 < param_2) {
      if (param_2 == 0x616) {
        *param_4 = '\x01';
        *param_3 = '!';
        return 0;
      }
      if (param_2 < 0x617) {
        if (param_2 < 0x307) {
          if (param_2 < 0x300) {
            return 6;
          }
          uVar1 = 1 << (param_2 - 0x300 & 0x1f);
          if ((uVar1 & 0x16) == 0) {
            if ((uVar1 & 0x21) == 0) {
              if ((uVar1 & 0x48) == 0) {
                return 6;
              }
              goto _L0;
            }
_L0:
            *param_4 = '\x01';
            *param_3 = '0';
            return 0;
          }
        }
        else {
          if (param_2 == 0x610) goto _L0;
          if (0x610 < param_2) {
            if (param_2 != 0x613) {
              if (param_2 < 0x614) {
                if (1 < (param_2 - 0x611 & 0xffff)) {
                  return 6;
                }
                goto _L0;
              }
              if (param_2 != 0x615) {
                return 6;
              }
            }
            goto _L0;
          }
          if (param_2 < 0x530) {
            if ((param_2 < 0x50f) && (0xff < (param_2 - 0x400 & 0xffff))) {
              return 6;
            }
          }
          else if (1 < (param_2 - 0x5fe & 0xffff)) {
            return 6;
          }
        }
      }
      else {
        if (param_2 == 0x617) goto _L0;
        if (param_2 < 0x617) {
          return 6;
        }
        if (param_2 == 0x619) goto _L0;
        if (param_2 != 0x620) {
          return 6;
        }
      }
_L0:
      *param_4 = '\x01';
      *param_3 = '#';
      return 0;
    }
    if (param_2 < 0x16f) {
      if (param_2 < 0x160) {
        if (param_2 < 0x10f) {
          if (param_2 < 0x100) {
            if (param_2 < 6) goto _L0;
            if (0x29 < (param_2 - 6 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
        }
        else if (param_2 < 0x13f) {
          if (param_2 < 0x130) {
            if (param_2 == 0x11f) goto _L0;
            if (param_2 < 0x120) {
              if (param_2 == 0x10f) goto _L0;
              if (param_2 < 0x10f) {
                return 6;
              }
              if (0xe < (param_2 - 0x110 & 0xffff)) {
                return 6;
              }
            }
            else {
              if (0x12e < param_2) {
                if (param_2 != 0x12f) {
                  return 6;
                }
                goto _L0;
              }
              if (param_2 < 0x120) {
                return 6;
              }
            }
          }
        }
        else {
          if (param_2 == 0x14f) {
_L0:
            *param_4 = '\x01';
            *param_3 = ' ';
            return 0;
          }
          if (param_2 < 0x150) {
            if (param_2 == 0x13f) goto _L0;
            if (param_2 < 0x13f) {
              return 6;
            }
            if (0xe < (param_2 - 0x140 & 0xffff)) {
              return 6;
            }
          }
          else {
            if (0x15e < param_2) {
              if (param_2 != 0x15f) {
                return 6;
              }
              goto _L0;
            }
            if (param_2 < 0x150) {
              return 6;
            }
          }
        }
      }
    }
    else {
      if (0x1ce < param_2) {
        if (param_2 < 0x1ff) {
          if (0x1ef < param_2) goto _L0;
          if (param_2 != 0x1df) {
            if (param_2 < 0x1e0) {
              if (param_2 == 0x1cf) goto _L0;
              if (param_2 < 0x1cf) {
                return 6;
              }
              if (0xe < (param_2 - 0x1d0 & 0xffff)) {
                return 6;
              }
            }
            else {
              if (0x1ee < param_2) {
                if (param_2 != 0x1ef) {
                  return 6;
                }
                goto _L0;
              }
              if (param_2 < 0x1e0) {
                return 6;
              }
            }
            goto _L0;
          }
        }
        else {
          if (0x203 < param_2) {
            return 6;
          }
          if (0x200 < param_2) goto _L0;
          if (param_2 != 0x1ff) {
            if (param_2 != 0x200) {
              return 6;
            }
            goto _L0;
          }
        }
        goto _L0;
      }
      if (param_2 < 0x1c0) {
        if (param_2 < 0x19f) {
          if (param_2 < 400) {
            if (param_2 == 0x17f) goto _L0;
            if (param_2 < 0x180) {
              if (param_2 == 0x16f) goto _L0;
              if (param_2 < 0x16f) {
                return 6;
              }
              if (0xe < (param_2 - 0x170 & 0xffff)) {
                return 6;
              }
            }
            else {
              if (0x18e < param_2) {
                if (param_2 != 399) {
                  return 6;
                }
                goto _L0;
              }
              if (param_2 < 0x180) {
                return 6;
              }
            }
          }
        }
        else {
          if (param_2 == 0x1af) goto _L0;
          if (param_2 < 0x1b0) {
            if (param_2 == 0x19f) goto _L0;
            if (param_2 < 0x19f) {
              return 6;
            }
            if (0xe < (param_2 - 0x1a0 & 0xffff)) {
              return 6;
            }
          }
          else {
            if (0x1be < param_2) {
              if (param_2 != 0x1bf) {
                return 6;
              }
              goto _L0;
            }
            if (param_2 < 0x1b0) {
              return 6;
            }
          }
        }
      }
    }
_L0:
    *param_4 = '\x01';
    *param_3 = '%';
    return 0;
  }
  if (param_2 < 0x833) {
    if (param_2 < 0x820) {
      if (param_2 != 0x802) {
        if (param_2 < 0x803) {
          if (param_2 != 0x702) {
            if (param_2 < 0x703) {
              if (param_2 != 0x700) {
                if (param_2 != 0x701) {
                  if (param_2 != 0x622) {
                    return 6;
                  }
                  goto _L0;
                }
                goto _L0;
              }
            }
            else {
              if (param_2 == 0x704) goto _L0;
              if (param_2 < 0x705) {
                if (param_2 != 0x703) {
                  return 6;
                }
                goto _L0;
              }
              if (param_2 != 0x800) {
                if (param_2 != 0x801) {
                  return 6;
                }
                goto _L0;
              }
            }
          }
          goto _L0;
        }
        if (param_2 != 0x80a) {
          if (param_2 < 0x80a) {
            return 6;
          }
          if (param_2 != 0x810) {
            if (param_2 < 0x811) {
              if (param_2 != 0x80b) {
                return 6;
              }
              goto _L0;
            }
            if (1 < (param_2 - 0x811 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
          goto _L0;
        }
      }
      *param_4 = '\x01';
      *param_3 = '+';
      return 0;
    }
    uVar1 = 1 << (param_2 - 0x820 & 0x1f);
    if ((uVar1 & 0x10001) != 0) goto _L0;
    if ((uVar1 & 0x20002) == 0) {
      if ((uVar1 & 0x40004) == 0) {
        return 6;
      }
_L0:
      *param_4 = '\x01';
      *param_3 = 'A';
      return 0;
    }
  }
  else if (param_2 < 0x8204) {
    if (0x8200 < param_2) goto _L0;
    if (param_2 < 0x8030) {
      if (0x7fff < param_2) {
_L0:
        *param_4 = '\x03';
        *param_3 = 'A';
        return 0;
      }
      if (0x852 < param_2) {
        return 6;
      }
      if (param_2 < 0x840) {
        return 6;
      }
      uVar1 = 1 << (param_2 - 0x840 & 0x1f);
      if ((uVar1 & 0x10001) != 0) goto _L0;
      if ((uVar1 & 0x20002) == 0) {
        if ((uVar1 & 0x40004) == 0) {
          return 6;
        }
        goto _L0;
      }
    }
    else {
      if (param_2 < 0x810f) {
        if (param_2 < 0x8100) {
          return 6;
        }
        goto _L0;
      }
      if (param_2 != 0x8200) {
        return 6;
      }
    }
  }
  else {
    if (param_2 == 0x8627) goto _L0;
    if (param_2 < 0x8628) {
      if (param_2 < 0x8614) {
        if (0x8610 < param_2) goto _L0;
        if (0x852f < param_2) {
          if (param_2 != 0x8610) {
            return 6;
          }
          goto _L0;
        }
        if ((param_2 < 0x850f) && (0xff < (param_2 + 0x7c00 & 0xffff))) {
          return 6;
        }
      }
      else if (param_2 != 0x8625) {
        if ((param_2 != 0x8626) && (param_2 != 0x8615)) {
          return 6;
        }
        goto _L0;
      }
      goto _L0;
    }
    if (param_2 != 0x8702) {
      if (param_2 < 0x8703) {
        if (param_2 == 0x8700) goto _L0;
        if (param_2 != 0x8701) {
          return 6;
        }
      }
      else if (param_2 != 0x8703) {
        if (param_2 != 0x8704) {
          return 6;
        }
        goto _L0;
      }
_L0:
      *param_4 = '\x01';
      *param_3 = '\"';
      return 0;
    }
  }
_L0:
  *param_4 = '\x01';
  *param_3 = -0x1e;
  return 0;
}

