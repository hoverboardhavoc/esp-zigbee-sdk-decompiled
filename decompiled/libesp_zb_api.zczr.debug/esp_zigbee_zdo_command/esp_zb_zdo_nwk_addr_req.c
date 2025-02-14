/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zdo_command.o -> esp_zb_zdo_nwk_addr_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_nwk_addr_req(undefined2 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  int iVar8;
  undefined2 *puVar9;
  undefined4 uVar10;
  
  iVar8 = zb_buf_get_out_func();
  if (param_1 == (undefined2 *)0x0) {
    uVar10 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_API_ZDO",&_LC19,uVar10,"ESP_ZIGBEE_API_ZDO",
                  "esp_zb_zdo_nwk_addr_req",0x238);
  }
  else if (iVar8 == 0) {
    uVar10 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_API_ZDO",&_L0,uVar10,"ESP_ZIGBEE_API_ZDO","esp_zb_zdo_nwk_addr_req",
                  0x239);
  }
  else {
    puVar9 = (undefined2 *)zb_buf_get_tail_func(0xc);
    *puVar9 = *param_1;
    uVar1 = *(undefined1 *)((int)param_1 + 3);
    uVar2 = *(undefined1 *)(param_1 + 2);
    uVar3 = *(undefined1 *)((int)param_1 + 5);
    uVar4 = *(undefined1 *)(param_1 + 3);
    uVar5 = *(undefined1 *)((int)param_1 + 7);
    uVar6 = *(undefined1 *)(param_1 + 4);
    uVar7 = *(undefined1 *)((int)param_1 + 9);
    *(undefined1 *)(puVar9 + 1) = *(undefined1 *)(param_1 + 1);
    *(undefined1 *)((int)puVar9 + 3) = uVar1;
    *(undefined1 *)(puVar9 + 2) = uVar2;
    *(undefined1 *)((int)puVar9 + 5) = uVar3;
    *(undefined1 *)(puVar9 + 3) = uVar4;
    *(undefined1 *)((int)puVar9 + 7) = uVar5;
    *(undefined1 *)(puVar9 + 4) = uVar6;
    *(undefined1 *)((int)puVar9 + 9) = uVar7;
    *(undefined1 *)(puVar9 + 5) = *(undefined1 *)(param_1 + 5);
    *(undefined1 *)((int)puVar9 + 0xb) = *(undefined1 *)((int)param_1 + 0xb);
    uVar10 = zb_zdo_nwk_addr_req(iVar8,device_nwk_addr_req_cb);
    zb_schedule_app_alarm(nwk_addr_req_timeout,uVar10,5000000,0);
    esp_zb_zdo_callback_register(uVar10,0,param_2,param_3);
  }
  return;
}

