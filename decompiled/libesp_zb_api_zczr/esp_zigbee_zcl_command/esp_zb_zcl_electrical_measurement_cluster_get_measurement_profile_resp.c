/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_electrical_measurement_cluster_get_measurement_profile_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_electrical_measurement_cluster_get_measurement_profile_resp(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  undefined1 *puVar6;
  char *pcVar7;
  undefined4 uVar8;
  
  iVar3 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if ((iVar3 != 0) && (iVar5 = zb_buf_get_out_func(), iVar5 != 0)) {
    puVar6 = (undefined1 *)zb_buf_reuse_func();
    *puVar6 = 0x19;
    pcVar7 = (char *)zb_zcl_get_ctx();
    cVar2 = *pcVar7;
    *pcVar7 = cVar2 + '\x01';
    puVar6[1] = cVar2;
    puVar6[2] = 1;
    puVar6 = (undefined1 *)zb_put_next_htole32(puVar6 + 3,*(undefined4 *)(param_1 + 0x10));
    *puVar6 = (char)*(undefined4 *)(param_1 + 0x14);
    puVar6[1] = (char)*(undefined4 *)(param_1 + 0x18);
    puVar6[2] = *(undefined1 *)(param_1 + 0x1c);
    uVar8 = zb_put_next_htole16(*(undefined1 *)(param_1 + 0x1d));
    zb_zcl_finish_and_send_packet
              (iVar5,uVar8,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),*(undefined2 *)(iVar3 + 1),
               *(undefined2 *)(param_1 + 0x24));
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

