/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_thermostat_set_weekly_schedule_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_thermostat_set_weekly_schedule_cmd_req(int param_1)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  byte *pbVar8;
  
  uVar4 = 0x104;
  iVar5 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar5 != 0) {
    uVar4 = *(undefined2 *)(iVar5 + 1);
  }
  iVar5 = zb_buf_get_out_func();
  if (iVar5 == 0) {
    pbVar8 = (byte *)zb_zcl_get_ctx();
    bVar2 = *pbVar8;
    *pbVar8 = bVar2 + 1;
    return bVar2;
  }
  puVar6 = (undefined1 *)zb_zcl_start_command_header(1,0,1,0);
  *puVar6 = *(undefined1 *)(param_1 + 0x10);
  puVar6[1] = *(undefined1 *)(param_1 + 0x11);
  puVar6[2] = *(undefined1 *)(param_1 + 0x12);
  uVar7 = zb_put_next_htole16(*(undefined2 *)(param_1 + 0x14));
  cVar1 = *(char *)(param_1 + 0x12);
  if (cVar1 == '\x01') {
    uVar3 = *(undefined2 *)(param_1 + 0x16);
  }
  else {
    if (cVar1 != '\x02') {
      if (cVar1 != '\x03') goto _L0;
      zb_put_next_htole16(*(undefined2 *)(param_1 + 0x16));
    }
    uVar3 = *(undefined2 *)(param_1 + 0x18);
  }
  uVar7 = zb_put_next_htole16(uVar3);
_L0:
  zb_zcl_finish_and_send_packet
            (iVar5,uVar7,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),uVar4,0x201);
  pbVar8 = (byte *)zb_buf_begin_func(iVar5);
  if ((*pbVar8 & 4) == 0) {
    iVar5 = 1;
  }
  else {
    iVar5 = 3;
  }
  return pbVar8[iVar5];
}

