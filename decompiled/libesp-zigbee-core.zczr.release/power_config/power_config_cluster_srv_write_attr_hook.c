/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> power_config.o -> power_config_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void power_config_cluster_srv_write_attr_hook(undefined4 param_1,uint param_2,ushort *param_3)

{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined1 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined1 auStack_2c [4];
  
  if (param_2 == 0) {
    if (param_3 == (ushort *)0x0) {
      return;
    }
    uVar2 = *param_3;
    iVar6 = zcl_get_attr_desc(1,0x10,0);
    if (iVar6 == 0) {
      return;
    }
    iVar7 = zcl_get_attr_desc(param_1,1,0x11,0);
    if (((iVar7 != 0) && (uVar2 < **(ushort **)(iVar7 + 8))) && (**(ushort **)(iVar7 + 8) != 0xffff)
       ) {
      **(byte **)(iVar6 + 8) = **(byte **)(iVar6 + 8) | 1;
      power_config_alarm(param_1,0);
    }
    iVar7 = zcl_get_attr_desc(param_1,1,0x12,0);
    if (iVar7 == 0) {
      return;
    }
    if (uVar2 <= **(ushort **)(iVar7 + 8)) {
      return;
    }
    **(byte **)(iVar6 + 8) = **(byte **)(iVar6 + 8) | 2;
    goto code_r0x00010000;
  }
  uVar8 = 0x20;
  if ((param_2 & 0xffffffbf) == 0x20) {
    if (param_3 == (ushort *)0x0) {
      return;
    }
    iVar6 = 1;
    if ((param_2 != (param_2 & 0xffbf)) && (iVar6 = 2, param_2 != 0x40)) {
      iVar6 = 3;
      param_2 = 0x60;
    }
_L0:
    bVar3 = false;
    uVar8 = param_2;
  }
  else {
    if (param_2 == 0x40) {
      iVar6 = 2;
      if (param_3 == (ushort *)0x0) {
        return;
      }
      goto _L0;
    }
    if ((param_2 & 0xffbf) == 0x21) {
      if (param_3 == (ushort *)0x0) {
        return;
      }
      if (param_2 == 0x21) {
        iVar6 = 1;
      }
      else {
        if (param_2 == 0x41) goto _L0;
        iVar6 = 3;
        uVar8 = 0x60;
      }
    }
    else {
      if (param_2 != 0x41) {
        return;
      }
      if (param_3 == (ushort *)0x0) {
        return;
      }
_L0:
      iVar6 = 2;
      uVar8 = 0x40;
    }
    bVar3 = true;
  }
  bVar1 = (byte)*param_3;
  if (uVar8 == 0x20) {
    uVar10 = 0x39;
    uVar11 = 0x38;
    uVar12 = 0x37;
    uVar13 = 0x36;
  }
  else if (uVar8 == 0x40) {
    uVar10 = 0x59;
    uVar11 = 0x58;
    uVar12 = 0x57;
    uVar13 = 0x56;
  }
  else {
    uVar10 = 0x79;
    uVar11 = 0x78;
    uVar12 = 0x77;
    uVar13 = 0x76;
  }
  if (bVar3) {
    if (uVar8 == 0x20) {
      uVar10 = 0x3d;
      uVar11 = 0x3c;
      uVar12 = 0x3b;
      uVar13 = 0x3a;
    }
    else if (uVar8 == 0x40) {
      uVar10 = 0x5d;
      uVar11 = 0x5c;
      uVar12 = 0x5b;
      uVar13 = 0x5a;
    }
    else {
      uVar10 = 0x7d;
      uVar11 = 0x7c;
      uVar12 = 0x7b;
      uVar13 = 0x7a;
    }
  }
  iVar7 = zcl_get_attr_desc(param_1,1,uVar8 + 0x1e & 0xffff,0);
  iVar4 = zcl_get_attr_desc(param_1,1,uVar8 + 0x15 & 0xffff,0);
  if ((iVar7 == 0) || (iVar4 == 0)) {
    return;
  }
  iVar5 = zcl_get_attr_desc(param_1,1,uVar13,0);
  if ((iVar5 == 0) || ((**(byte **)(iVar5 + 8) <= bVar1 || (**(byte **)(iVar5 + 8) == 0xff)))) {
    iVar5 = zcl_get_attr_desc(param_1,1,uVar12,0);
    if ((iVar5 == 0) || ((**(byte **)(iVar5 + 8) <= bVar1 || (**(byte **)(iVar5 + 8) == 0xff)))) {
      iVar5 = zcl_get_attr_desc(param_1,1,uVar11,0);
      if ((iVar5 == 0) || ((**(byte **)(iVar5 + 8) <= bVar1 || (**(byte **)(iVar5 + 8) == 0xff)))) {
        iVar5 = zcl_get_attr_desc(param_1,1,uVar10,0);
        if (iVar5 == 0) {
          return;
        }
        if (**(byte **)(iVar5 + 8) <= bVar1) {
          return;
        }
        if (**(byte **)(iVar5 + 8) == 0xff) {
          return;
        }
        iVar5 = 3;
        uVar9 = 8;
      }
      else {
        iVar5 = 2;
        uVar9 = 4;
      }
    }
    else {
      iVar5 = 1;
      uVar9 = 2;
    }
  }
  else {
    iVar5 = 0;
    uVar9 = 1;
  }
  **(undefined1 **)(iVar4 + 8) = uVar9;
  **(int **)(iVar7 + 8) = (iVar6 << ((iVar6 + -1) * 10 & 0x1fU)) + iVar5;
code_r0x00010000:
  iVar6 = af_get_ep_desc();
  if ((iVar6 != 0) && (iVar6 = af_endpoint_get_cluster_desc(9,1), iVar6 != 0)) {
    memset(auStack_2c,0,0x1a);
    ezb_zcl_alarms_alarm_cmd_req(auStack_2c);
  }
  return;
}

