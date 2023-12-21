/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
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
  zb_zcl_frame_get_sequence_number(uVar2);
  return;
}

