/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
thermostat_cluster_srv_check_value_handler(uint param_1,undefined4 param_2,ushort *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  ushort uVar4;
  byte bVar5;
  byte bVar6;
  ushort uVar7;
  uint uVar8;
  char cVar9;
  short sStack_24;
  short asStack_22 [3];
  
  sStack_24 = 0;
  asStack_22[0] = 0;
  if (param_1 == 0x24) {
    uVar4 = *param_3;
    uVar7 = 0x5a0;
    goto _L0;
  }
  if (0x24 < param_1) {
    if (param_1 == 0x39) {
      uVar3 = 0x38;
_L0:
      iVar1 = thermostat_srv_get_attr_desc(param_2,uVar3);
      if ((iVar1 == 0) || (bVar5 = **(byte **)(iVar1 + 8), bVar5 <= (byte)*param_3)) goto _L0;
    }
    else {
      if (0x39 < param_1) {
        if (param_1 == 0x45) {
          bVar5 = 4;
          bVar6 = (byte)*param_3 - 1;
        }
        else {
          if (0x45 < param_1) {
            if (param_1 == 0x46) goto _L0;
            if ((param_1 == 0x47) && ((byte)*param_3 == 0)) {
              return 0x87;
            }
            goto _L0;
          }
          if (param_1 == 0x40) {
            bVar5 = 3;
            bVar6 = (byte)*param_3 - 1;
          }
          else {
            if (1 < (param_1 - 0x42 & 0xffff)) goto _L0;
            bVar5 = 2;
            bVar6 = (byte)*param_3 - 1;
          }
        }
_L190:
        if (bVar5 < bVar6) {
          return 0x87;
        }
        goto _L0;
      }
      if (param_1 == 0x36) {
        uVar3 = 0x35;
        goto _L0;
      }
      if (param_1 < 0x37) {
        if (param_1 == 0x34) {
          iVar1 = thermostat_srv_get_attr_desc(param_2,0x35);
          iVar2 = thermostat_srv_get_attr_desc(param_2,0x36);
          if ((iVar1 != 0) && ((byte)*param_3 < **(byte **)(iVar1 + 8))) goto _L0;
          iVar1 = 0;
          if (iVar2 == 0) goto _L0;
_L0:
          if (**(byte **)(iVar2 + 8) < (byte)*param_3) {
            return 0x87;
          }
          if (iVar1 != 0) {
            return 0x87;
          }
          goto _L0;
        }
        if (param_1 != 0x35) {
          if (param_1 == 0x32) goto _L0;
          goto _L0;
        }
        uVar3 = 0x36;
      }
      else {
        uVar3 = 0x39;
        if (param_1 == 0x37) {
          iVar1 = thermostat_srv_get_attr_desc(param_2,0x38);
          iVar2 = thermostat_srv_get_attr_desc(param_2,0x39);
          if ((iVar1 == 0) || (**(byte **)(iVar1 + 8) <= (byte)*param_3)) {
            if (iVar2 != 0) {
              iVar1 = 0;
              goto _L0;
            }
            goto _L0;
          }
_L0:
          iVar1 = 0x87;
          if (iVar2 == 0) {
            return 0x87;
          }
          goto _L0;
        }
      }
      iVar1 = thermostat_srv_get_attr_desc(param_2,uVar3);
      if ((iVar1 == 0) || (bVar5 = **(byte **)(iVar1 + 8), (byte)*param_3 <= bVar5)) goto _L0;
    }
_L0:
    *(byte *)param_3 = bVar5;
    goto _L0;
  }
  if (param_1 < 0x17) {
    if (0x14 < param_1) {
      iVar1 = thermostat_srv_get_attr_desc(param_2,3);
      uVar3 = 4;
_L0:
      iVar2 = thermostat_srv_get_attr_desc(param_2,uVar3);
      if ((iVar1 == 0) || (iVar2 == 0)) {
_L0:
        sStack_24 = -0x6ab3;
        asStack_22[0] = 0x7fff;
      }
      else {
        sStack_24 = **(short **)(iVar1 + 8);
        asStack_22[0] = **(short **)(iVar2 + 8);
      }
_L0:
      if ((short)*param_3 < sStack_24) {
        return 0x87;
      }
      if (asStack_22[0] < (short)*param_3) {
        return 0x87;
      }
      goto _L0;
    }
    if (param_1 == 8) {
      iVar1 = thermostat_srv_get_attr_desc(param_2,0x1c);
      if (iVar1 == 0) {
_L96:
        iVar1 = __assert_func(0,0,0,0);
        goto _L0;
      }
      if (**(char **)(iVar1 + 8) == '\0') {
        return 0x87;
      }
      if (**(char **)(iVar1 + 8) == '\x03') {
        return 0x87;
      }
    }
    else {
      if (8 < param_1) {
        if (param_1 == 0x12) {
_L0:
          thermostat_get_heat_setpoint_limit_part_0(param_2,&sStack_24,asStack_22);
          goto _L0;
        }
        if (param_1 < 0x13) {
          if (param_1 == 0x10) {
            if ((char)(byte)*param_3 < -0x19) {
              bVar5 = 0xe7;
            }
            else {
              bVar5 = 0x19;
              if ((char)(byte)*param_3 < '\x1a') goto _L0;
            }
            goto _L0;
          }
          if (param_1 != 0x11) goto _L0;
        }
        else if (param_1 != 0x13) goto _L0;
        thermostat_get_cool_setpoint_limit_part_0(param_2,&sStack_24,asStack_22);
        goto _L0;
      }
      if (param_1 < 2) goto _L0;
      if (param_1 != 7) goto _L0;
      iVar1 = thermostat_srv_get_attr_desc(param_2,0x1c);
      if (iVar1 == 0) goto _L96;
_L0:
      if ((**(byte **)(iVar1 + 8) & 0xfb) == 0) {
        return 0x87;
      }
    }
    uVar4 = (ushort)(byte)*param_3;
    uVar7 = 100;
_L0:
    if (uVar7 < uVar4) {
      return 0x87;
    }
  }
  else if (param_1 == 0x1c) {
    if (9 < (byte)*param_3) {
      return 0x87;
    }
    if ((byte)*param_3 == 2) {
      return 0x87;
    }
    iVar1 = thermostat_srv_get_attr_desc(param_2,0x1b);
    if (iVar1 != 0) {
      if (**(byte **)(iVar1 + 8) < 2) {
        bVar5 = (byte)*param_3;
joined_r0x00010548:
        if ((byte)(bVar5 - 4) < 2) {
          return 0x87;
        }
      }
      else if ((byte)(**(byte **)(iVar1 + 8) - 2) < 2) {
        bVar5 = (byte)*param_3;
_L0:
        if (bVar5 == 3) {
          return 0x87;
        }
        if (bVar5 == 6) {
          return 0x87;
        }
      }
    }
  }
  else {
    if (0x1c < param_1) {
      if (param_1 == 0x20) {
        uVar4 = (ushort)(byte)*param_3;
        uVar7 = 6;
      }
      else {
        if (param_1 != 0x23) {
          if ((param_1 == 0x1e) && ((byte)*param_3 != 0)) {
            bVar6 = (byte)*param_3 - 3;
            bVar5 = 1;
            goto _L190;
          }
          goto _L0;
        }
        uVar4 = (ushort)(byte)*param_3;
        uVar7 = 1;
      }
      goto _L0;
    }
    if (param_1 == 0x19) {
      if (0x19 < (byte)*param_3) {
        return 0x87;
      }
    }
    else {
      if (param_1 < 0x1a) {
        iVar1 = thermostat_srv_get_attr_desc(param_2,5);
        uVar3 = 6;
        goto _L0;
      }
      if (param_1 == 0x1b) {
        if (5 < (byte)*param_3) {
          return 0x87;
        }
        iVar1 = thermostat_srv_get_attr_desc(param_2);
        if (iVar1 != 0) {
          bVar5 = **(byte **)(iVar1 + 8);
          if ((byte)*param_3 < 2) goto joined_r0x00010548;
          if ((byte)((byte)*param_3 - 2) < 2) goto _L0;
        }
      }
    }
  }
_L0:
  iVar1 = thermostat_srv_get_attr_desc(param_2,0x19);
  cVar9 = '\0';
  if (iVar1 != 0) {
    cVar9 = **(char **)(iVar1 + 8);
  }
  if (param_1 == 0x13) {
    uVar8 = 0x14;
_L0:
    iVar1 = thermostat_srv_get_attr_desc(param_2,uVar8);
    if (iVar1 == 0) {
      return 0;
    }
    if ((int)**(short **)(iVar1 + 8) + cVar9 * 10 <= (int)(short)*param_3) {
      return 0;
    }
  }
  else {
    if (param_1 < 0x14) {
      uVar8 = 0x12;
      if (param_1 == 0x11) goto _L0;
    }
    else {
      uVar8 = 0x14;
    }
    if (((param_1 != uVar8) || (iVar1 = thermostat_srv_get_attr_desc(param_2), iVar1 == 0)) ||
       ((int)(short)*param_3 <= (int)**(short **)(iVar1 + 8) + cVar9 * -10)) {
      return 0;
    }
  }
  return 0x87;
}

