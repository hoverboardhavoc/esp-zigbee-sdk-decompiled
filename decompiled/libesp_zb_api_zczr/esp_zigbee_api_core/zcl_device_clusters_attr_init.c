/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_core.o -> zcl_device_clusters_attr_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_device_clusters_attr_init(undefined1 param_1,undefined4 param_2)

{
  byte bVar1;
  short sVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  undefined2 uStack_40;
  byte bStack_3e;
  int iStack_3c;
  undefined1 uStack_38;
  
  iVar6 = zb_af_get_endpoint_desc(param_2);
  bVar1 = *(byte *)(iVar6 + 0x10);
  for (iVar9 = 0; iVar9 < (int)(uint)bVar1; iVar9 = iVar9 + 1) {
    memcpy(&uStack_40,(void *)(iVar9 * 0xf + *(int *)(iVar6 + 0x11)),0xf);
    uVar8 = (uint)bStack_3e;
    for (iVar5 = 0; uVar4 = uStack_38, uVar3 = uStack_40, iVar5 < (int)uVar8; iVar5 = iVar5 + 1) {
      sVar2 = *(short *)(iStack_3c + iVar5 * 8);
      if (((sVar2 != -1) && (sVar2 != -3)) && (sVar2 != -0x1001)) {
        uVar7 = get_default_attribute_value(uStack_40,sVar2);
        zb_zcl_set_attr_val(param_2,uVar3,uVar4,sVar2,uVar7,0);
      }
    }
  }
  zb_zcl_init_reporting_info();
  zb_zcl_reset_reporting_ctx();
  zb_nvram_write_dataset(2);
  zb_nvram_write_dataset(3);
  if (zcl_basic_reset_factory_user_cb != (code *)0x0) {
    (*zcl_basic_reset_factory_user_cb)(param_1,param_2);
  }
  return;
}

