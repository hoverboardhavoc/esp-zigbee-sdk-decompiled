/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_match_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zdo_match_cluster(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined2 *puVar6;
  int iVar7;
  
  iVar2 = (uint)(byte)param_1[6] + (uint)(byte)param_1[7];
  uVar3 = zb_buf_get_out_func();
  puVar4 = (undefined1 *)zb_buf_initial_alloc_func((iVar2 + 5) * 2);
  if (puVar4 == (undefined1 *)0x0) {
    uVar5 = 0x101;
  }
  else {
    *puVar4 = *param_1;
    puVar4[1] = param_1[1];
    puVar4[2] = param_1[2];
    puVar4[3] = (char)((ushort)*(undefined2 *)(param_1 + 2) >> 8);
    puVar4[4] = param_1[4];
    puVar4[5] = param_1[5];
    puVar4[6] = param_1[6];
    puVar4[7] = param_1[7];
    for (iVar7 = 0;
        (puVar6 = *(undefined2 **)(param_1 + 8), puVar6 != (undefined2 *)0x0 && (iVar7 < iVar2));
        iVar7 = (iVar7 + 1) * 0x10000 >> 0x10) {
      uVar1 = *puVar6;
      puVar4[iVar7 * 2 + 8] = (char)uVar1;
      puVar4[iVar7 * 2 + 9] = (char)((ushort)uVar1 >> 8);
      *(undefined2 **)(param_1 + 8) = puVar6 + 1;
    }
    uVar5 = 0x104;
    if (iVar2 == iVar7) {
      uVar3 = zb_zdo_match_desc_req(uVar3,find_device_cb);
      zb_schedule_app_alarm(match_desc_req_device_timeout,uVar3,0x14a,0);
      esp_zb_zdo_callback_register(uVar3,6,param_2,param_3);
      uVar5 = 0;
    }
  }
  return uVar5;
}

