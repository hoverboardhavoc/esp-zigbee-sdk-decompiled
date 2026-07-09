/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_finish_tx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_finish_tx(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  char cStack_1b;
  ushort uStack_1a;
  ushort uStack_18;
  ushort uStack_16;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 uStack_11;
  
  cStack_1b = '\0';
  zmsg_read_le16_isra_0(0,&uStack_16);
  zmsg_read_le16_isra_0(param_1,4,&uStack_1a);
  zmsg_read_le16_isra_0(param_1,2,&uStack_18);
  if ((uStack_16 & 3) == 1) {
    uVar1 = zmsg_get_offset(param_1);
    zmsg_read_u8_isra_0(param_1,uVar1,&cStack_1b);
  }
  if ((*(ushort *)(param_1 + 0x16) & 8) == 0) {
    nwk_handle_data_confirm(param_1,param_2);
    return;
  }
  if (((param_2 != 0) && (uStack_18 < 0xfff8)) && (cStack_1b != '\x03')) {
    if ((uStack_16 & 0x400) == 0) {
      iVar2 = nwk_route_table_find();
      if (iVar2 == 0) goto _L0;
      if ((*(ushort *)(iVar2 + 0xe) & 0x10) == 0) {
        uStack_13 = (undefined1)uStack_18;
        uStack_12 = (undefined1)(uStack_18 >> 8);
        uStack_14 = 2;
      }
      else {
        uStack_13 = (undefined1)uStack_1a;
        uStack_14 = 0xc;
        uStack_12 = (undefined1)(uStack_1a >> 8);
        uStack_1a = uStack_18;
      }
    }
    else {
      uStack_13 = (undefined1)uStack_18;
      uStack_12 = (undefined1)(uStack_18 >> 8);
      uStack_14 = 0xb;
    }
    uStack_11 = 0;
    nwk_send_status(uStack_1a,&uStack_14);
    nwk_handle_network_status_local(&uStack_14);
  }
_L0:
  zmsg_free(param_1);
  return;
}

