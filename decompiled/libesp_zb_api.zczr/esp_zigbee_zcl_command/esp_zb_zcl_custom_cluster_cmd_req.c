/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_custom_cluster_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_custom_cluster_cmd_req(int param_1)

{
  byte *pbVar1;
  uint uVar2;
  byte *pbVar3;
  undefined4 uVar4;
  int iVar5;
  byte bVar6;
  
  uVar2 = esp_zb_zcl_get_attribute_size
                    (*(undefined1 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24));
  if ((uVar2 != 0xffff) || (uVar2 = (uint)*(ushort *)(param_1 + 0x20), uVar2 != 0xffff)) {
    iVar5 = 0x5a;
    if ((*(byte *)(param_1 + 0x14) & 3) != 0) {
      iVar5 = 0x5c;
    }
    iVar5 = zb_buf_get_func(0,iVar5 + uVar2);
    if (iVar5 != 0) {
      pbVar3 = (byte *)zb_buf_reuse_func();
      bVar6 = 1;
      if ((*(byte *)(param_1 + 0x14) & 3) != 0) {
        bVar6 = 5;
      }
      pbVar1 = pbVar3 + 1;
      *pbVar3 = bVar6 | (byte)((*(uint *)(param_1 + 0x14) & 0xc) << 1);
      if ((*(byte *)(param_1 + 0x14) & 3) != 0) {
        pbVar1 = (byte *)zb_put_next_htole16(pbVar1,*(undefined2 *)(param_1 + 0x16));
      }
      pbVar3 = (byte *)zb_zcl_get_ctx();
      bVar6 = *pbVar3;
      *pbVar3 = bVar6 + 1;
      *pbVar1 = bVar6;
      pbVar1[1] = (byte)*(undefined2 *)(param_1 + 0x18);
      uVar4 = esp_zb_zcl_put_attribute_value
                        (pbVar1 + 2,*(undefined1 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24),
                         uVar2);
      zb_zcl_finish_and_send_packet
                (iVar5,uVar4,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
                 *(undefined1 *)(param_1 + 9),*(undefined2 *)(param_1 + 0x10),
                 *(undefined2 *)(param_1 + 0x12));
      pbVar3 = (byte *)zb_buf_begin_func(iVar5);
      if ((*pbVar3 & 4) == 0) {
        iVar5 = 1;
      }
      else {
        iVar5 = 3;
      }
      return pbVar3[iVar5];
    }
  }
  pbVar3 = (byte *)zb_zcl_get_ctx();
  bVar6 = *pbVar3;
  *pbVar3 = bVar6 + 1;
  return bVar6;
}

