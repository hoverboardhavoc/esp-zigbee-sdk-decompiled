/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_ias_wd_start_warning_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_ias_wd_start_warning_cmd_req(int param_1)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  undefined2 uVar7;
  
  uVar7 = 0x104;
  iVar4 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar4 != 0) {
    uVar7 = *(undefined2 *)(iVar4 + 1);
  }
  iVar4 = zb_buf_get_out_func();
  if (iVar4 == 0) {
    pbVar5 = (byte *)zb_zcl_get_ctx();
    bVar1 = *pbVar5;
    *pbVar5 = bVar1 + 1;
    return bVar1;
  }
  bVar1 = *(byte *)(param_1 + 0x12);
  cVar2 = *(char *)(param_1 + 0x10);
  bVar3 = *(byte *)(param_1 + 0x11);
  pbVar5 = (byte *)zb_zcl_start_command_header(1,0,0,0);
  *pbVar5 = bVar1 & 3 | cVar2 << 4 | (byte)((bVar3 & 3) << 2);
  puVar6 = (undefined1 *)zb_put_next_htole16(pbVar5 + 1,*(undefined2 *)(param_1 + 0x14));
  *puVar6 = *(undefined1 *)(param_1 + 0x16);
  puVar6[1] = *(undefined1 *)(param_1 + 0x17);
  zb_zcl_finish_and_send_packet
            (iVar4,puVar6 + 2,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),uVar7,0x502);
  pbVar5 = (byte *)zb_buf_begin_func(iVar4);
  if ((*pbVar5 & 4) == 0) {
    iVar4 = 1;
  }
  else {
    iVar4 = 3;
  }
  return pbVar5[iVar4];
}

