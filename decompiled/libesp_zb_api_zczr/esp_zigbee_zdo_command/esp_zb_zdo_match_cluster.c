/*
 * Last changed at upstream commit c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * https://github.com/espressif/esp-zigbee-sdk/commit/c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * Upstream date: 2023-08-30 15:00:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.3(6da46788)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_match_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zdo_match_cluster(undefined2 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int iVar5;
  
  iVar2 = (uint)*(byte *)(param_1 + 3) + (uint)*(byte *)((int)param_1 + 7);
  uVar3 = zb_buf_get_out_func();
  puVar4 = (undefined1 *)zb_buf_initial_alloc_func((iVar2 + 5) * 2);
  if (puVar4 == (undefined1 *)0x0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC24,uVar3,0x10000,"esp_zb_zdo_match_cluster",0x15c);
    uVar3 = 0x101;
  }
  else {
    uVar1 = *param_1;
    *puVar4 = (char)uVar1;
    puVar4[1] = (char)((ushort)uVar1 >> 8);
    uVar1 = param_1[1];
    puVar4[2] = (char)uVar1;
    puVar4[3] = (char)((ushort)uVar1 >> 8);
    uVar1 = param_1[2];
    puVar4[4] = (char)uVar1;
    puVar4[5] = (char)((ushort)uVar1 >> 8);
    puVar4[6] = *(undefined1 *)(param_1 + 3);
    puVar4[7] = *(undefined1 *)((int)param_1 + 7);
    for (iVar5 = 0; (*(undefined2 **)(param_1 + 4) != (undefined2 *)0x0 && (iVar5 < iVar2));
        iVar5 = (iVar5 + 1) * 0x10000 >> 0x10) {
      uVar1 = **(undefined2 **)(param_1 + 4);
      puVar4[iVar5 * 2 + 8] = (char)uVar1;
      puVar4[iVar5 * 2 + 9] = (char)((ushort)uVar1 >> 8);
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 2;
    }
    if (iVar5 == iVar2) {
      uVar3 = zb_zdo_match_desc_req(uVar3,find_device_cb);
      zb_schedule_app_alarm(match_desc_req_device_timeout,uVar3,0x14a);
      esp_zb_zdo_callback_register(uVar3,6,param_2,param_3);
      uVar3 = 0;
    }
    else {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC25,uVar3,0x10000,"esp_zb_zdo_match_cluster",0x167);
      uVar3 = 0x104;
    }
  }
  return uVar3;
}

