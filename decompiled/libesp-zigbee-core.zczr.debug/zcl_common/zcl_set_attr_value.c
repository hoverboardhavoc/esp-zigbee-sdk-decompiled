/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_common.o -> zcl_set_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t
zcl_set_attr_value(uint8_t ep_id,uint16_t cluster_id,uint8_t cluster_role,uint16_t attr_id,
                  uint16_t manuf_code,void *value,_Bool check_access)

{
  undefined3 in_register_00002029;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 in_register_0000202e;
  undefined3 in_register_00002031;
  undefined2 in_register_00002036;
  undefined4 uVar5;
  undefined2 in_register_0000203a;
  undefined3 in_register_00002041;
  
  uVar5 = CONCAT22(in_register_00002036,attr_id);
  uVar1 = CONCAT31(in_register_00002029,ep_id);
  iVar2 = zcl_get_attr_desc();
  if (iVar2 == 0) {
    iVar4 = 1;
  }
  else if (value == (void *)0x0) {
    iVar4 = 1;
  }
  else {
    if (CONCAT31(in_register_00002041,check_access) != 0) {
      if ((*(byte *)(iVar2 + 3) & 2) == 0) {
        iVar4 = 0x88;
        goto _L0;
      }
      if ((*(byte *)(iVar2 + 3) & 0x40) != 0) {
        iVar4 = 0x8c;
        goto _L0;
      }
    }
    iVar3 = zcl_cluster_template_find
                      (CONCAT22(in_register_0000202e,cluster_id),
                       CONCAT31(in_register_00002031,cluster_role));
    if (iVar3 == 0) {
      iVar4 = 0;
    }
    else if (*(code **)(iVar3 + 4) == (code *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = (**(code **)(iVar3 + 4))(uVar5,uVar1,value);
    }
    if (iVar4 == 0) {
      if ((iVar3 != 0) && (*(code **)(iVar3 + 8) != (code *)0x0)) {
        (**(code **)(iVar3 + 8))(uVar1,uVar5,value,CONCAT22(in_register_0000203a,manuf_code));
      }
      zcl_write_attr_value(*(uint8_t **)(iVar2 + 8),value,*(zcl_attr_type_t *)(iVar2 + 2));
      zcl_reporting_mark_attr_change
                (uVar1,CONCAT22(in_register_0000202e,cluster_id),
                 CONCAT31(in_register_00002031,cluster_role),uVar5,
                 CONCAT22(in_register_0000203a,manuf_code));
    }
  }
_L0:
  return (zcl_status_t)iVar4;
}

