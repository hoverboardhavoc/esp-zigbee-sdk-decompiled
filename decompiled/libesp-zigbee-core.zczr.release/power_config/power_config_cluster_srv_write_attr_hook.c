/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> power_config.o -> power_config_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void power_config_cluster_srv_write_attr_hook
               (uint8_t endpoint,uint16_t attr_id,void *new_value,uint16_t manuf_code)

{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined3 in_register_00002029;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined2 in_register_0000202e;
  uint uVar10;
  undefined1 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined1 auStack_2c [4];
  
  uVar10 = CONCAT22(in_register_0000202e,attr_id);
  uVar6 = CONCAT31(in_register_00002029,endpoint);
  if (uVar10 == 0) {
    if (new_value == (void *)0x0) {
      return;
    }
                    /* WARNING: Load size is inaccurate */
    uVar2 = *new_value;
    iVar7 = zcl_get_attr_desc(1,0x10,0);
    if (iVar7 == 0) {
      return;
    }
    iVar8 = zcl_get_attr_desc(uVar6,1,0x11,0);
    if (((iVar8 != 0) && (uVar2 < **(ushort **)(iVar8 + 8))) && (**(ushort **)(iVar8 + 8) != 0xffff)
       ) {
      **(byte **)(iVar7 + 8) = **(byte **)(iVar7 + 8) | 1;
      power_config_alarm(endpoint,'\0');
    }
    iVar8 = zcl_get_attr_desc(uVar6,1,0x12,0);
    if (iVar8 == 0) {
      return;
    }
    if (uVar2 <= **(ushort **)(iVar8 + 8)) {
      return;
    }
    **(byte **)(iVar7 + 8) = **(byte **)(iVar7 + 8) | 2;
    goto code_r0x00010000;
  }
  uVar9 = 0x20;
  if ((uVar10 & 0xffffffbf) == 0x20) {
    if (new_value == (void *)0x0) {
      return;
    }
    iVar7 = 1;
    if ((uVar10 != (attr_id & 0xffbf)) && (iVar7 = 2, uVar10 != 0x40)) {
      iVar7 = 3;
      uVar10 = 0x60;
    }
_L0:
    bVar3 = false;
    uVar9 = uVar10;
  }
  else {
    if (uVar10 == 0x40) {
      iVar7 = 2;
      if (new_value == (void *)0x0) {
        return;
      }
      goto _L0;
    }
    if ((attr_id & 0xffbf) == 0x21) {
      if (new_value == (void *)0x0) {
        return;
      }
      if (uVar10 == 0x21) {
        iVar7 = 1;
      }
      else {
        if (uVar10 == 0x41) goto _L0;
        iVar7 = 3;
        uVar9 = 0x60;
      }
    }
    else {
      if (uVar10 != 0x41) {
        return;
      }
      if (new_value == (void *)0x0) {
        return;
      }
_L0:
      iVar7 = 2;
      uVar9 = 0x40;
    }
    bVar3 = true;
  }
                    /* WARNING: Load size is inaccurate */
  bVar1 = *new_value;
  if (uVar9 == 0x20) {
    uVar12 = 0x39;
    uVar13 = 0x38;
    uVar14 = 0x37;
    uVar15 = 0x36;
  }
  else if (uVar9 == 0x40) {
    uVar12 = 0x59;
    uVar13 = 0x58;
    uVar14 = 0x57;
    uVar15 = 0x56;
  }
  else {
    uVar12 = 0x79;
    uVar13 = 0x78;
    uVar14 = 0x77;
    uVar15 = 0x76;
  }
  if (bVar3) {
    if (uVar9 == 0x20) {
      uVar12 = 0x3d;
      uVar13 = 0x3c;
      uVar14 = 0x3b;
      uVar15 = 0x3a;
    }
    else if (uVar9 == 0x40) {
      uVar12 = 0x5d;
      uVar13 = 0x5c;
      uVar14 = 0x5b;
      uVar15 = 0x5a;
    }
    else {
      uVar12 = 0x7d;
      uVar13 = 0x7c;
      uVar14 = 0x7b;
      uVar15 = 0x7a;
    }
  }
  iVar8 = zcl_get_attr_desc(uVar6,1,uVar9 + 0x1e & 0xffff,0);
  iVar4 = zcl_get_attr_desc(uVar6,1,uVar9 + 0x15 & 0xffff,0);
  if ((iVar8 == 0) || (iVar4 == 0)) {
    return;
  }
  iVar5 = zcl_get_attr_desc(uVar6,1,uVar15,0);
  if ((iVar5 == 0) || ((**(byte **)(iVar5 + 8) <= bVar1 || (**(byte **)(iVar5 + 8) == 0xff)))) {
    iVar5 = zcl_get_attr_desc(uVar6,1,uVar14,0);
    if ((iVar5 == 0) || ((**(byte **)(iVar5 + 8) <= bVar1 || (**(byte **)(iVar5 + 8) == 0xff)))) {
      iVar5 = zcl_get_attr_desc(uVar6,1,uVar13,0);
      if ((iVar5 == 0) || ((**(byte **)(iVar5 + 8) <= bVar1 || (**(byte **)(iVar5 + 8) == 0xff)))) {
        iVar5 = zcl_get_attr_desc(uVar6,1,uVar12,0);
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
        uVar11 = 8;
      }
      else {
        iVar5 = 2;
        uVar11 = 4;
      }
    }
    else {
      iVar5 = 1;
      uVar11 = 2;
    }
  }
  else {
    iVar5 = 0;
    uVar11 = 1;
  }
  **(undefined1 **)(iVar4 + 8) = uVar11;
  **(int **)(iVar8 + 8) = (iVar7 << ((iVar7 + -1) * 10 & 0x1fU)) + iVar5;
code_r0x00010000:
  iVar7 = af_get_ep_desc();
  if ((iVar7 != 0) && (iVar7 = af_endpoint_get_cluster_desc(9,1), iVar7 != 0)) {
    memset(auStack_2c,0,0x1a);
    ezb_zcl_alarms_alarm_cmd_req(auStack_2c);
  }
  return;
}

