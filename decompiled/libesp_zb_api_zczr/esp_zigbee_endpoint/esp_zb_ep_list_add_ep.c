/*
 * Last changed at upstream commit ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * https://github.com/espressif/esp-zigbee-sdk/commit/ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * Upstream date: 2024-03-15 18:43:30 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.1(aaf0078d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_endpoint.o -> esp_zb_ep_list_add_ep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
esp_zb_ep_list_add_ep(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined4 extraout_a1;
  void *pvVar5;
  undefined1 uStack_38;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  puVar3 = (undefined1 *)malloc(0x28);
  if (param_1 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_L0,uVar4,0x10000);
    uVar4 = 0x102;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x24);
    do {
      iVar2 = iVar1;
      if (iVar2 == 0) break;
      iVar1 = *(int *)(iVar2 + 0x24);
    } while (*(int *)(iVar2 + 0x24) != 0);
    uStack_28 = zcl_convert_cluster_list_to_array(param_2);
    uStack_38 = (undefined1)param_3;
    *puVar3 = uStack_38;
    puVar3[1] = (char)((uint)param_3 >> 8);
    puVar3[2] = (char)((uint)param_3 >> 0x10);
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[5] = 0;
    puVar3[6] = 0;
    puVar3[7] = 0;
    puVar3[8] = 0;
    puVar3[9] = 0;
    puVar3[10] = 0;
    puVar3[0xb] = 0;
    *(undefined4 *)(puVar3 + 0xc) = 0;
    puVar3[0x10] = (undefined1)uStack_28;
    puVar3[0x11] = (char)extraout_a1;
    puVar3[0x12] = (char)((uint)extraout_a1 >> 8);
    puVar3[0x13] = (char)((uint)extraout_a1 >> 0x10);
    puVar3[0x14] = (char)((uint)extraout_a1 >> 0x18);
    uStack_24 = extraout_a1;
    uVar4 = zcl_get_simple_desc(&uStack_28,param_4);
    puVar3[0x15] = (char)uVar4;
    puVar3[0x16] = (char)((uint)uVar4 >> 8);
    puVar3[0x17] = (char)((uint)uVar4 >> 0x10);
    puVar3[0x18] = (char)((uint)uVar4 >> 0x18);
    puVar3[0x1a] = uStack_28._1_1_;
    if (uStack_28._1_1_ == 0) {
      pvVar5 = (void *)0x0;
    }
    else {
      pvVar5 = calloc((uint)uStack_28._1_1_,0x38);
    }
    puVar3[0x1b] = (char)pvVar5;
    puVar3[0x1c] = (char)((uint)pvVar5 >> 8);
    puVar3[0x1d] = (char)((uint)pvVar5 >> 0x10);
    puVar3[0x1e] = (char)((uint)pvVar5 >> 0x18);
    puVar3[0x1f] = 1;
    pvVar5 = calloc(1,7);
    *(void **)(puVar3 + 0x20) = pvVar5;
    *(undefined4 *)(puVar3 + 0x24) = 0;
    if (iVar2 == 0) {
      *(undefined1 **)(param_1 + 0x24) = puVar3;
      uVar4 = 0;
    }
    else {
      *(undefined1 **)(iVar2 + 0x24) = puVar3;
      uVar4 = 0;
    }
  }
  return uVar4;
}

