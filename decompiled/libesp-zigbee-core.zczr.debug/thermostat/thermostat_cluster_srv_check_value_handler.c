/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte thermostat_cluster_srv_check_value_handler(uint param_1,undefined4 param_2,ushort *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  byte bVar6;
  short sStack_24;
  short asStack_22 [5];
  
  asStack_22[0] = 0;
  sStack_24 = 0;
  pcVar5 = (char *)param_3;
  if (param_1 == 0x23) {
_L0:
    if ((byte)*(ushort *)pcVar5 < 2) {
      bVar6 = 0;
    }
    else {
      bVar6 = 0x87;
    }
_L0:
    if (bVar6 != 0) {
      return bVar6;
    }
  }
  else {
    if (0x23 < param_1) {
      if (param_1 == 0x39) {
        iVar2 = thermostat_srv_get_attr_desc(param_2,0x38);
        if (iVar2 == 0) {
          bVar6 = 0;
        }
        else if ((byte)*param_3 < **(byte **)(iVar2 + 8)) {
          *(byte *)param_3 = **(byte **)(iVar2 + 8);
          bVar6 = 0;
        }
        else {
          bVar6 = 0;
        }
      }
      else if (param_1 < 0x3a) {
        if (param_1 == 0x35) {
          iVar2 = thermostat_srv_get_attr_desc(param_2,0x36);
          if (iVar2 == 0) {
            bVar6 = 0;
          }
          else if (**(byte **)(iVar2 + 8) < (byte)*param_3) {
            *(byte *)param_3 = **(byte **)(iVar2 + 8);
            bVar6 = 0;
          }
          else {
            bVar6 = 0;
          }
        }
        else if (param_1 < 0x36) {
          if (param_1 == 0x32) goto _L0;
          if (param_1 == 0x34) {
            iVar2 = thermostat_srv_get_attr_desc(param_2,0x35);
            iVar3 = thermostat_srv_get_attr_desc(param_2,0x36);
            if (iVar2 == 0) {
              bVar6 = 0;
            }
            else if ((byte)*param_3 < **(byte **)(iVar2 + 8)) {
              bVar6 = 0x87;
            }
            else {
              bVar6 = 0;
            }
            if ((iVar3 != 0) && (**(byte **)(iVar3 + 8) < (byte)*param_3)) {
              bVar6 = 0x87;
            }
          }
          else if (param_1 == 0x24) {
            if (*param_3 < 0x5a1) {
              bVar6 = 0;
            }
            else {
              bVar6 = 0x87;
            }
          }
          else {
            bVar6 = 0;
          }
        }
        else if (param_1 == 0x37) {
          iVar2 = thermostat_srv_get_attr_desc(param_2,0x38);
          iVar3 = thermostat_srv_get_attr_desc(param_2,0x39);
          if (iVar2 == 0) {
            bVar6 = 0;
          }
          else if ((byte)*param_3 < **(byte **)(iVar2 + 8)) {
            bVar6 = 0x87;
          }
          else {
            bVar6 = 0;
          }
          if ((iVar3 != 0) && (**(byte **)(iVar3 + 8) < (byte)*param_3)) {
            bVar6 = 0x87;
          }
        }
        else if (param_1 == 0x38) {
          iVar2 = thermostat_srv_get_attr_desc(param_2,0x39);
          if (iVar2 == 0) {
            bVar6 = 0;
          }
          else if (**(byte **)(iVar2 + 8) < (byte)*param_3) {
            *(byte *)param_3 = **(byte **)(iVar2 + 8);
            bVar6 = 0;
          }
          else {
            bVar6 = 0;
          }
        }
        else if (param_1 == 0x36) {
          iVar2 = thermostat_srv_get_attr_desc(param_2,0x35);
          if (iVar2 == 0) {
            bVar6 = 0;
          }
          else if ((byte)*param_3 < **(byte **)(iVar2 + 8)) {
            *(byte *)param_3 = **(byte **)(iVar2 + 8);
            bVar6 = 0;
          }
          else {
            bVar6 = 0;
          }
        }
        else {
          bVar6 = 0;
        }
      }
      else if (param_1 == 0x45) {
        if ((byte)((byte)*param_3 - 1) < 5) {
          bVar6 = 0;
        }
        else {
          bVar6 = 0x87;
        }
      }
      else if (param_1 < 0x46) {
        if (param_1 == 0x42) {
          if ((byte)((byte)*param_3 - 1) < 3) {
            bVar6 = 0;
          }
          else {
            bVar6 = 0x87;
          }
        }
        else if (param_1 == 0x43) {
          if ((byte)((byte)*param_3 - 1) < 3) {
            bVar6 = 0;
          }
          else {
            bVar6 = 0x87;
          }
        }
        else if (param_1 == 0x40) {
          if ((byte)((byte)*param_3 - 1) < 4) {
            bVar6 = 0;
          }
          else {
            bVar6 = 0x87;
          }
        }
        else {
          bVar6 = 0;
        }
      }
      else {
        if (param_1 == 0x46) {
          asStack_22[0] = -0x6ab3;
          sStack_24 = 0x7fff;
          goto _L0;
        }
        if (param_1 == 0x47) {
          if ((byte)*param_3 == 0) {
            bVar6 = 0x87;
          }
          else {
            bVar6 = 0;
          }
        }
        else {
          bVar6 = 0;
        }
      }
      goto _L0;
    }
    if (0x16 < param_1) {
      if (param_1 == 0x1c) {
        if ((byte)*param_3 < 10) {
          if ((byte)*param_3 == 2) {
            bVar6 = 0x87;
          }
          else {
            iVar2 = thermostat_srv_get_attr_desc(param_2,0x1b);
            if (iVar2 == 0) {
              bVar6 = 0;
            }
            else if (**(byte **)(iVar2 + 8) < 2) {
              if ((byte)((byte)*param_3 - 4) < 2) {
                bVar6 = 0x87;
              }
              else {
                bVar6 = 0;
              }
            }
            else if ((byte)(**(byte **)(iVar2 + 8) - 2) < 2) {
              if ((byte)*param_3 == 3) {
                bVar6 = 0x87;
              }
              else if ((byte)*param_3 == 6) {
                bVar6 = 0x87;
              }
              else {
                bVar6 = 0;
              }
            }
            else {
              bVar6 = 0;
            }
          }
        }
        else {
          bVar6 = 0x87;
        }
      }
      else if (param_1 < 0x1d) {
        if (param_1 == 0x19) {
          if ((byte)*param_3 < 0x1a) {
            bVar6 = 0;
          }
          else {
            bVar6 = 0x87;
          }
        }
        else if (param_1 < 0x1a) {
          if ((param_1 - 0x17 & 0xffff) < 2) {
            iVar2 = thermostat_srv_get_attr_desc(param_2,5);
            iVar3 = thermostat_srv_get_attr_desc(param_2,6);
            if ((iVar2 == 0) || (iVar3 == 0)) {
              asStack_22[0] = -0x6ab3;
              sStack_24 = 0x7fff;
            }
            else {
              asStack_22[0] = **(short **)(iVar2 + 8);
              sStack_24 = **(short **)(iVar3 + 8);
            }
            goto _L0;
          }
          bVar6 = 0;
        }
        else if (param_1 == 0x1b) {
          if ((byte)*param_3 < 6) {
            iVar2 = thermostat_srv_get_attr_desc(param_2,0x1c);
            if (iVar2 == 0) {
              bVar6 = 0;
            }
            else {
              cVar1 = **(char **)(iVar2 + 8);
              if ((byte)*param_3 < 2) {
                if ((byte)(cVar1 - 4U) < 2) {
                  bVar6 = 0x87;
                }
                else {
                  bVar6 = 0;
                }
              }
              else if ((byte)((byte)*param_3 - 2) < 2) {
                if (cVar1 == '\x03') {
                  bVar6 = 0x87;
                }
                else if (cVar1 == '\x06') {
                  bVar6 = 0x87;
                }
                else {
                  bVar6 = 0;
                }
              }
              else {
                bVar6 = 0;
              }
            }
          }
          else {
            bVar6 = 0x87;
          }
        }
        else {
          bVar6 = 0;
        }
      }
      else if (param_1 == 0x1e) {
        bVar6 = (byte)*param_3;
        if (bVar6 == 3) {
          bVar6 = 0;
        }
        else if (bVar6 == 4) {
          bVar6 = 0;
        }
        else if (bVar6 != 0) {
          bVar6 = 0x87;
        }
      }
      else if (param_1 == 0x20) {
        if ((byte)*param_3 < 7) {
          bVar6 = 0;
        }
        else {
          bVar6 = 0x87;
        }
      }
      else {
        bVar6 = 0;
      }
      goto _L0;
    }
    if (0x14 < param_1) {
      iVar2 = thermostat_srv_get_attr_desc(param_2,3);
      iVar3 = thermostat_srv_get_attr_desc(param_2,4);
      if ((iVar2 == 0) || (iVar3 == 0)) {
        asStack_22[0] = -0x6ab3;
        sStack_24 = 0x7fff;
      }
      else {
        asStack_22[0] = **(short **)(iVar2 + 8);
        sStack_24 = **(short **)(iVar3 + 8);
      }
      goto _L0;
    }
    if (param_1 == 8) {
_L0:
      iVar2 = thermostat_srv_get_attr_desc(param_2,0x1c);
      if (iVar2 == 0) {
        pcVar5 = "thermostat_cluster_srv_check_value_handler";
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/thermostat.c",
                      0x365,"attr_desc");
        goto _L0;
      }
      if (**(char **)(iVar2 + 8) == '\0') {
        bVar6 = 0x87;
      }
      else if (**(char **)(iVar2 + 8) == '\x03') {
        bVar6 = 0x87;
      }
      else if ((byte)*param_3 < 0x65) {
        bVar6 = 0;
      }
      else {
        bVar6 = 0x87;
      }
      goto _L0;
    }
    if (param_1 < 9) {
      if (param_1 != 1) {
        if (param_1 == 7) {
          iVar2 = thermostat_srv_get_attr_desc(param_2,0x1c);
          if (iVar2 == 0) {
            __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/thermostat.c",
                          0x358,"thermostat_cluster_srv_check_value_handler","attr_desc");
            goto _L0;
          }
          if (**(char **)(iVar2 + 8) == '\0') {
            bVar6 = 0x87;
          }
          else if (**(char **)(iVar2 + 8) == '\x04') {
            bVar6 = 0x87;
          }
          else if ((byte)*param_3 < 0x65) {
            bVar6 = 0;
          }
          else {
            bVar6 = 0x87;
          }
        }
        else {
          if (param_1 == 0) {
            asStack_22[0] = -0x6ab3;
            sStack_24 = 0x7fff;
            goto _L0;
          }
          bVar6 = 0;
        }
        goto _L0;
      }
      asStack_22[0] = -0x6ab3;
      sStack_24 = 0x7fff;
    }
    else {
      if (param_1 != 0x12) {
        if (param_1 < 0x13) {
          if (param_1 == 0x10) {
            bVar6 = (byte)*param_3;
            if (((char)bVar6 < -0x19) || ('\x19' < (char)bVar6)) {
              if ((char)bVar6 < '\0') {
                bVar6 = 0xe7;
              }
              else {
                bVar6 = 0x19;
              }
              *(byte *)param_3 = bVar6;
              bVar6 = 0;
            }
            else {
              bVar6 = 0;
            }
          }
          else {
            if (param_1 == 0x11) goto _L0;
            bVar6 = 0;
          }
        }
        else {
          if (param_1 == 0x13) {
_L0:
            thermostat_get_cool_setpoint_limit(param_2,asStack_22,&sStack_24);
            goto _L0;
          }
          if (param_1 == 0x14) goto _L0;
          bVar6 = 0;
        }
        goto _L0;
      }
_L0:
      thermostat_get_heat_setpoint_limit(param_2,asStack_22,&sStack_24);
    }
_L0:
    if ((short)*param_3 < asStack_22[0]) {
      return 0x87;
    }
    if (sStack_24 < (short)*param_3) {
      return 0x87;
    }
    bVar6 = 0;
  }
  iVar2 = thermostat_srv_get_attr_desc(param_2,0x19);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (int)**(char **)(iVar2 + 8);
  }
  if (param_1 == 0x13) {
_L0:
    if (param_1 == 0x11) {
      uVar4 = 0x12;
    }
    else {
      uVar4 = 0x14;
    }
    iVar3 = thermostat_srv_get_attr_desc(param_2,uVar4);
    if (iVar3 != 0) {
      if ((int)(short)*param_3 < iVar2 * 10 + (int)**(short **)(iVar3 + 8)) {
        bVar6 = 0x87;
      }
      else {
        bVar6 = 0;
      }
    }
  }
  else {
    if (param_1 < 0x14) {
      if (param_1 == 0x11) goto _L0;
      if (param_1 != 0x12) {
        return bVar6;
      }
    }
    else if (param_1 != 0x14) {
      return bVar6;
    }
    if (param_1 == 0x12) {
      uVar4 = 0x11;
    }
    else {
      uVar4 = 0x13;
    }
    iVar3 = thermostat_srv_get_attr_desc(param_2,uVar4);
    if (iVar3 != 0) {
      if ((int)**(short **)(iVar3 + 8) + iVar2 * -10 < (int)(short)*param_3) {
        bVar6 = 0x87;
      }
      else {
        bVar6 = 0;
      }
    }
  }
  return bVar6;
}

