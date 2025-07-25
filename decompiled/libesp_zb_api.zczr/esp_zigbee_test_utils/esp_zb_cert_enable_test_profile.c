/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_test_utils.o -> esp_zb_cert_enable_test_profile
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_cert_enable_test_profile
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined2 *puVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  
  if (param_1 == 0x103) {
    calloc(1,0x30);
    iVar4 = 10;
    puVar6 = out_cluster_list_0103_1;
    puVar1 = in_cluster_list_0103_2;
  }
  else {
    if (param_1 != 0x7f01) {
      return;
    }
    puVar6 = (undefined1 *)&cluster_list_7f01_0;
    calloc(1,0x20);
    iVar4 = 6;
    puVar1 = (undefined1 *)&cluster_list_7f01_0;
  }
  zb_set_simple_descriptor(param_2,param_1,param_3,param_4,iVar4,iVar4);
  uVar5 = 0;
  do {
    puVar3 = (undefined2 *)((int)puVar1 + uVar5 * 2);
    uVar2 = uVar5 & 0xff;
    uVar5 = uVar5 + 1;
    zb_set_input_cluster_id(uVar2,*puVar3);
  } while ((int)uVar5 < iVar4);
  uVar5 = 0;
  do {
    puVar3 = (undefined2 *)((int)puVar6 + uVar5 * 2);
    uVar2 = uVar5 & 0xff;
    uVar5 = uVar5 + 1;
    zb_set_output_cluster_id(uVar2,*puVar3);
  } while ((int)uVar5 < iVar4);
  zb_add_simple_descriptor();
  return;
}

