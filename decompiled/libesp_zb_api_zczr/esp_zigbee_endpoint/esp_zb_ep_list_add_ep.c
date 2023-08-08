/*
 * Last changed at upstream commit d04ab25a7353bae74042267d24c5fef5f02d0726
 * https://github.com/espressif/esp-zigbee-sdk/commit/d04ab25a7353bae74042267d24c5fef5f02d0726
 * Upstream date: 2023-08-08 16:02:31 +0800
 * Upstream subject: esp-zigbee-sdk: add touchlink example
 * Source: libesp_zb_api_zczr -> esp_zigbee_endpoint.o -> esp_zb_ep_list_add_ep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
esp_zb_ep_list_add_ep
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  void *pvVar7;
  
  puVar4 = (undefined1 *)malloc(0x28);
  if (param_1 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC4,uVar5,0x10000);
    uVar5 = 0x102;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x24);
    do {
      iVar3 = iVar2;
      if (iVar3 == 0) break;
      iVar2 = *(int *)(iVar3 + 0x24);
    } while (*(int *)(iVar3 + 0x24) != 0);
    uVar5 = zcl_get_cluster_lists(param_2);
    puVar6 = (undefined1 *)zcl_get_cluster_info(param_2);
    *puVar4 = (char)param_3;
    puVar4[1] = (char)param_4;
    puVar4[2] = (char)((uint)param_4 >> 8);
    puVar4[3] = 0;
    puVar4[4] = 0;
    puVar4[5] = 0;
    puVar4[6] = 0;
    puVar4[7] = 0;
    puVar4[8] = 0;
    puVar4[9] = 0;
    puVar4[10] = 0;
    puVar4[0xb] = 0;
    *(undefined4 *)(puVar4 + 0xc) = 0;
    puVar4[0x10] = *puVar6;
    puVar4[0x11] = (char)uVar5;
    puVar4[0x12] = (char)((uint)uVar5 >> 8);
    puVar4[0x13] = (char)((uint)uVar5 >> 0x10);
    puVar4[0x14] = (char)((uint)uVar5 >> 0x18);
    uVar5 = zcl_get_simple_desc(param_2,puVar6,param_3,param_4,param_5);
    puVar4[0x15] = (char)uVar5;
    puVar4[0x16] = (char)((uint)uVar5 >> 8);
    puVar4[0x17] = (char)((uint)uVar5 >> 0x10);
    puVar4[0x18] = (char)((uint)uVar5 >> 0x18);
    bVar1 = puVar6[1];
    puVar4[0x1a] = bVar1;
    if (bVar1 == 0) {
      pvVar7 = (void *)0x0;
    }
    else {
      pvVar7 = calloc((uint)bVar1,0x30);
    }
    puVar4[0x1b] = (char)pvVar7;
    puVar4[0x1c] = (char)((uint)pvVar7 >> 8);
    puVar4[0x1d] = (char)((uint)pvVar7 >> 0x10);
    puVar4[0x1e] = (char)((uint)pvVar7 >> 0x18);
    puVar4[0x1f] = 1;
    pvVar7 = calloc(1,7);
    *(void **)(puVar4 + 0x20) = pvVar7;
    *(undefined4 *)(puVar4 + 0x24) = 0;
    if (iVar3 == 0) {
      *(undefined1 **)(param_1 + 0x24) = puVar4;
      uVar5 = 0;
    }
    else {
      *(undefined1 **)(iVar3 + 0x24) = puVar4;
      uVar5 = 0;
    }
  }
  return uVar5;
}

