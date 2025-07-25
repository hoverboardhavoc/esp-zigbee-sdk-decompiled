/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_mgmt_nwk_update_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_mgmt_nwk_update_req(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  if (param_1 == (undefined1 *)0x0) {
    return;
  }
  iVar1 = zb_buf_get_out_func();
  if (iVar1 != 0) {
    puVar2 = (undefined1 *)zb_buf_get_tail_func(10);
    puVar2[8] = param_1[8];
    puVar2[9] = param_1[9];
    puVar2[6] = param_1[6];
    puVar2[7] = (char)((ushort)*(undefined2 *)(param_1 + 6) >> 8);
    puVar2[5] = param_1[5];
    *puVar2 = *param_1;
    puVar2[1] = param_1[1];
    puVar2[2] = param_1[2];
    puVar2[3] = param_1[3];
    puVar2[4] = param_1[4];
    uVar3 = zb_zdo_mgmt_nwk_update_req(iVar1,zb_zdo_nwk_update_req_cb);
    zb_schedule_app_alarm(nwk_update_req_timeout,uVar3,5000000,0);
    esp_zb_zdo_callback_register(uVar3,0x38,param_2,param_3);
    return;
  }
  return;
}

