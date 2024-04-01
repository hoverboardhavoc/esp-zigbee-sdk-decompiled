/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_on_off_on_with_timed_off_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_on_off_on_with_timed_off_cmd_req(int param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  
  iVar2 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if ((iVar2 != 0) && (iVar4 = zb_buf_get_out_func(), iVar4 != 0)) {
    puVar5 = (undefined1 *)zb_zcl_start_command_header(1,0,0x42,0);
    *puVar5 = *(undefined1 *)(param_1 + 0x10);
    zb_put_next_htole16(*(undefined2 *)(param_1 + 0x12));
    uVar6 = zb_put_next_htole16(*(undefined2 *)(param_1 + 0x14));
    zb_zcl_finish_and_send_packet
              (iVar4,uVar6,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),*(undefined2 *)(iVar2 + 1),6);
    pbVar3 = (byte *)zb_buf_begin_func(iVar4);
    if ((*pbVar3 >> 2 & 1) == 0) {
      iVar2 = 1;
    }
    else {
      iVar2 = 3;
    }
    return pbVar3[iVar2];
  }
  pbVar3 = (byte *)zb_zcl_get_ctx();
  bVar1 = *pbVar3;
  *pbVar3 = bVar1 + 1;
  return bVar1;
}

