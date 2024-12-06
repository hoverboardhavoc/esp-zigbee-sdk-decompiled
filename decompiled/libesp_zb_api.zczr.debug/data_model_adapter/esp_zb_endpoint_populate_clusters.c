/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> data_model_adapter.o -> esp_zb_endpoint_populate_clusters
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_endpoint_populate_clusters(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  size_t __nmemb;
  void *pvVar3;
  undefined4 extraout_a1;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_18 = esp_zb_convert_cluster_list_to_array(*(undefined4 *)(param_1 + 0x11));
  iVar1 = *(int *)(param_1 + 0xc);
  *(undefined1 *)(param_1 + 0xc) = 0;
  *(undefined1 *)(param_1 + 0xd) = 0;
  *(undefined1 *)(param_1 + 0xe) = 0;
  *(undefined1 *)(param_1 + 0xf) = 0;
  uStack_14 = extraout_a1;
  if (iVar1 == 0) {
    __nmemb = zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/utility/data_model_adapter.c"
                        ,0xeb);
  }
  else {
    *(undefined1 *)(param_1 + 0x10) = (undefined1)uStack_18;
    *(char *)(param_1 + 0x11) = (char)extraout_a1;
    *(char *)(param_1 + 0x12) = (char)((uint)extraout_a1 >> 8);
    *(char *)(param_1 + 0x13) = (char)((uint)extraout_a1 >> 0x10);
    *(char *)(param_1 + 0x14) = (char)((uint)extraout_a1 >> 0x18);
    uVar2 = esp_zb_zcl_get_simple_desc(&uStack_18);
    *(char *)(param_1 + 0x15) = (char)uVar2;
    *(char *)(param_1 + 0x16) = (char)((uint)uVar2 >> 8);
    *(char *)(param_1 + 0x17) = (char)((uint)uVar2 >> 0x10);
    *(char *)(param_1 + 0x18) = (char)((uint)uVar2 >> 0x18);
    __nmemb = (size_t)uStack_18._1_1_;
    *(byte *)(param_1 + 0x1a) = uStack_18._1_1_;
    if (__nmemb == 0) {
      pvVar3 = (void *)0x0;
      goto _L0;
    }
  }
  pvVar3 = calloc(__nmemb,0x38);
_L0:
  *(char *)(param_1 + 0x1b) = (char)pvVar3;
  *(char *)(param_1 + 0x1c) = (char)((uint)pvVar3 >> 8);
  *(char *)(param_1 + 0x1d) = (char)((uint)pvVar3 >> 0x10);
  *(char *)(param_1 + 0x1e) = (char)((uint)pvVar3 >> 0x18);
  *(undefined1 *)(param_1 + 0x1f) = 1;
  pvVar3 = calloc(1,7);
  *(char *)(param_1 + 0x20) = (char)pvVar3;
  *(char *)(param_1 + 0x21) = (char)((uint)pvVar3 >> 8);
  *(char *)(param_1 + 0x22) = (char)((uint)pvVar3 >> 0x10);
  *(char *)(param_1 + 0x23) = (char)((uint)pvVar3 >> 0x18);
  return 0;
}

