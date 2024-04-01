/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_disc_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_disc_attr_cmd_req(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  undefined1 *puVar8;
  
  iVar3 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if ((iVar3 != 0) && (iVar5 = zb_buf_get_out_func(), iVar5 != 0)) {
    pcVar6 = (char *)zb_buf_reuse_func();
    *pcVar6 = (*(int *)(param_1 + 0x18) != 0) << 3;
    pcVar7 = (char *)zb_zcl_get_ctx();
    cVar2 = *pcVar7;
    *pcVar7 = cVar2 + '\x01';
    pcVar6[1] = cVar2;
    pcVar6[2] = '\f';
    puVar8 = (undefined1 *)zb_put_next_htole16(pcVar6 + 3,*(undefined2 *)(param_1 + 0x12));
    *puVar8 = *(undefined1 *)(param_1 + 0x14);
    zb_zcl_finish_and_send_packet
              (iVar5,puVar8 + 1,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),*(undefined2 *)(iVar3 + 1),
               *(undefined2 *)(param_1 + 0x10));
    pbVar4 = (byte *)zb_buf_begin_func(iVar5);
    if ((*pbVar4 >> 2 & 1) == 0) {
      iVar3 = 1;
    }
    else {
      iVar3 = 3;
    }
    return pbVar4[iVar3];
  }
  pbVar4 = (byte *)zb_zcl_get_ctx();
  bVar1 = *pbVar4;
  *pbVar4 = bVar1 + 1;
  return bVar1;
}

