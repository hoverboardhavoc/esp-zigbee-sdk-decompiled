/*
 * Last changed at upstream commit 37b2129eea9960f95d70bf2e6607337834e2750d
 * https://github.com/espressif/esp-zigbee-sdk/commit/37b2129eea9960f95d70bf2e6607337834e2750d
 * Upstream date: 2023-10-10 17:40:24 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.0(8d71c0ae)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_thermostat_set_weekly_schedule_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_thermostat_set_weekly_schedule_cmd_req(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  
  uVar2 = zb_buf_get_out_func();
  puVar3 = (undefined1 *)zb_zcl_start_command_header(1,0,1,0);
  *puVar3 = *(undefined1 *)(param_1 + 0x10);
  puVar3[1] = *(undefined1 *)(param_1 + 0x11);
  puVar3[2] = *(undefined1 *)(param_1 + 0x12);
  uVar4 = zb_put_next_htole16(puVar3 + 3,*(undefined2 *)(param_1 + 0x14));
  cVar1 = *(char *)(param_1 + 0x12);
  if (cVar1 == '\x01') {
    uVar4 = zb_put_next_htole16(*(undefined2 *)(param_1 + 0x16));
  }
  else if (cVar1 == '\x02') {
    uVar4 = zb_put_next_htole16(*(undefined2 *)(param_1 + 0x18));
  }
  else if (cVar1 == '\x03') {
    zb_put_next_htole16(*(undefined2 *)(param_1 + 0x16));
    uVar4 = zb_put_next_htole16(*(undefined2 *)(param_1 + 0x18));
  }
  zb_zcl_finish_and_send_packet
            (uVar2,uVar4,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),0x104,0x201);
  return;
}

