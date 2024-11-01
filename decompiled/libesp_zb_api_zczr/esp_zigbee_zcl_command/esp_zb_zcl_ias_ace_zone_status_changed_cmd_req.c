/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_ias_ace_zone_status_changed_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_ias_ace_zone_status_changed_cmd_req(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 *puVar4;
  void *pvVar5;
  byte *pbVar6;
  
  uVar2 = 0x104;
  iVar3 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar3 != 0) {
    uVar2 = *(undefined2 *)(iVar3 + 1);
  }
  iVar3 = zb_buf_get_out_func();
  if (iVar3 == 0) {
    pbVar6 = (byte *)zb_zcl_get_ctx();
    bVar1 = *pbVar6;
    *pbVar6 = bVar1 + 1;
    return bVar1;
  }
  puVar4 = (undefined1 *)zb_zcl_start_command_header(9,0,3,0);
  *puVar4 = *(undefined1 *)(param_1 + 0x10);
  puVar4 = (undefined1 *)zb_put_next_htole16(*(uint *)(param_1 + 0x10) >> 8 & 0xffff);
  *puVar4 = *(undefined1 *)(param_1 + 0x13);
  bVar1 = *(byte *)(param_1 + 0x14);
  puVar4[1] = bVar1;
  pvVar5 = memcpy(puVar4 + 2,(void *)(param_1 + 0x15),(uint)bVar1);
  zb_zcl_finish_and_send_packet
            (iVar3,(int)pvVar5 + (uint)*(byte *)(param_1 + 0x14),param_1,
             *(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),uVar2,0x501);
  pbVar6 = (byte *)zb_buf_begin_func(iVar3);
  if ((*pbVar6 & 4) == 0) {
    iVar3 = 1;
  }
  else {
    iVar3 = 3;
  }
  return pbVar6[iVar3];
}

