/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_test_utils.o -> esp_zb_cert_enable_test_profile
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_cert_enable_test_profile
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  
  if (param_1 == 0x103) {
    pvVar4 = calloc(1,0x30);
    iVar5 = 10;
    iVar1 = -0x658;
    iVar2 = -0x644;
  }
  else {
    if (param_1 != 0x7f01) {
      return;
    }
    pvVar4 = calloc(1,0x20);
    iVar5 = 6;
    iVar1 = -0x664;
    iVar2 = -0x664;
  }
  zb_set_simple_descriptor(pvVar4,param_2,param_1,param_3,param_4,iVar5,iVar5);
  for (uVar3 = 0; (int)uVar3 < iVar5; uVar3 = uVar3 + 1) {
    zb_set_input_cluster_id
              (pvVar4,uVar3 & 0xff,*(undefined2 *)(zb_buf_get_out_func + uVar3 * 2 + iVar2));
  }
  for (uVar3 = 0; (int)uVar3 < iVar5; uVar3 = uVar3 + 1) {
    zb_set_output_cluster_id
              (pvVar4,uVar3 & 0xff,*(undefined2 *)(zb_buf_get_out_func + uVar3 * 2 + iVar1));
  }
  zb_add_simple_descriptor(pvVar4);
  return;
}

