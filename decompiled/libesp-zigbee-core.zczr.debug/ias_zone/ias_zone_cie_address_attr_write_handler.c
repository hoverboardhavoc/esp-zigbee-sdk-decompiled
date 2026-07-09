/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_cie_address_attr_write_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ias_zone_cie_address_attr_write_handler
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  undefined2 uStack_36;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_2c [2];
  undefined2 uStack_2a;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  
  if ((*param_4 != 0 || param_4[1] != 0) &&
     (iVar1 = ias_zone_srv_get_zone_ctx(), *(char *)(iVar1 + 2) == '\0')) {
    uStack_36 = 0xffff;
    iVar2 = nwk_address_ref_by_short(param_3,&uStack_36);
    if ((iVar2 == 0) || (iVar2 = nwk_address_update(param_4,param_3,&uStack_36), iVar2 == 0)) {
      iVar2 = param_4[1];
      auStack_2c[0] = 3;
      uStack_34._0_2_ = (undefined2)(int3)*param_4;
      uStack_34._2_2_ = (undefined2)((uint)*param_4 >> 0x10);
      uStack_30._0_2_ = (undefined2)(int3)param_4[1];
      uStack_30._2_2_ = (undefined2)((uint)iVar2 >> 0x10);
      uStack_2a = (undefined2)uStack_34;
      uStack_28 = uStack_34._2_2_;
      uStack_26 = (undefined2)uStack_30;
      uStack_24 = uStack_30._2_2_;
      uStack_34 = *param_4;
      uStack_30 = iVar2;
      nwk_get_extended_address();
      iVar2 = aps_bind_table_add(param_1,0x500,auStack_2c,param_2);
      if (iVar2 != 0) {
        log_write(1,"ZCL_IAS_ZONE","Failed to add binding to the cie: %d",iVar2);
      }
      *(undefined1 *)(iVar1 + 2) = 1;
    }
    else {
      log_write(1,"ZCL_IAS_ZONE",0x10100,iVar2);
    }
  }
  return;
}

