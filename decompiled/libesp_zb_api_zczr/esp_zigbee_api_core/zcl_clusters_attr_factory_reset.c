/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_core.o -> zcl_clusters_attr_factory_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_clusters_attr_factory_reset(undefined1 *param_1)

{
  byte bVar1;
  undefined1 uVar2;
  short sVar3;
  undefined2 uVar4;
  undefined1 uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  undefined2 uStack_40;
  byte bStack_3e;
  int iStack_3c;
  undefined1 uStack_38;
  
  bVar1 = param_1[0x10];
  for (iVar9 = 0; iVar9 < (int)(uint)bVar1; iVar9 = iVar9 + 1) {
    memcpy(&uStack_40,(void *)(iVar9 * 0xf + *(int *)(param_1 + 0x11)),0xf);
    uVar8 = (uint)bStack_3e;
    for (iVar6 = 0; uVar5 = uStack_38, uVar4 = uStack_40, iVar6 < (int)uVar8; iVar6 = iVar6 + 1) {
      sVar3 = *(short *)(iStack_3c + iVar6 * 8);
      if (((sVar3 != -1) && (sVar3 != -3)) && (sVar3 != -0x1001)) {
        uVar2 = *param_1;
        uVar7 = get_default_attribute_value(uStack_40,sVar3);
        zb_zcl_set_attr_val(uVar2,uVar4,uVar5,sVar3,uVar7,0);
      }
    }
  }
  zb_zcl_init_reporting_info();
  zb_zcl_reset_reporting_ctx();
  return;
}

