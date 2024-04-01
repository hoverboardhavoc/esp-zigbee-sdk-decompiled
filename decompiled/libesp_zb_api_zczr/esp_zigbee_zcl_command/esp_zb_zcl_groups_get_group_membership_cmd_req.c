/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_groups_get_group_membership_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_groups_get_group_membership_cmd_req(int param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  
  iVar4 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if ((iVar4 != 0) && (iVar6 = zb_buf_get_out_func(), iVar6 != 0)) {
    pcVar7 = (char *)zb_zcl_start_command_header(1,0,2,0);
    cVar2 = *(char *)(param_1 + 0x10);
    pcVar8 = pcVar7 + 1;
    *pcVar7 = cVar2;
    if (cVar2 != '\0') {
      for (uVar3 = 0; uVar3 < *(byte *)(param_1 + 0x10); uVar3 = uVar3 + 1 & 0xff) {
        pcVar8 = (char *)zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x14) + uVar3 * 2));
      }
    }
    zb_zcl_finish_and_send_packet
              (iVar6,pcVar8,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),*(undefined2 *)(iVar4 + 1),4);
    pbVar5 = (byte *)zb_buf_begin_func(iVar6);
    if ((*pbVar5 >> 2 & 1) == 0) {
      iVar4 = 1;
    }
    else {
      iVar4 = 3;
    }
    return pbVar5[iVar4];
  }
  pbVar5 = (byte *)zb_zcl_get_ctx();
  bVar1 = *pbVar5;
  *pbVar5 = bVar1 + 1;
  return bVar1;
}

