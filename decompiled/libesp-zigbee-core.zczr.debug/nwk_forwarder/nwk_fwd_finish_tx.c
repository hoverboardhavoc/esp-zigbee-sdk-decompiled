/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_finish_tx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_finish_tx(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  char cStack_17;
  ushort uStack_16;
  ushort uStack_14;
  undefined2 auStack_12 [3];
  
  cStack_17 = '\0';
  zmsg_read_bytes(0,2,&uStack_16);
  zmsg_read_bytes(param_1,4,2,auStack_12);
  zmsg_read_bytes(param_1,2,&uStack_14);
  if ((uStack_16 & 3) == 1) {
    uVar1 = zmsg_get_offset(param_1);
    zmsg_read_bytes(param_1,uVar1,1,&cStack_17);
  }
  if ((*(ushort *)(param_1 + 0x16) & 8) == 0) {
    nwk_handle_data_confirm(param_1,param_2);
  }
  else {
    if (((param_2 != 0) && (uStack_14 < 0xfff8)) && (cStack_17 != '\x03')) {
      if ((uStack_16 & 0x400) == 0) {
        iVar2 = nwk_route_table_find(uStack_14);
        if (iVar2 != 0) {
          if ((*(ushort *)(iVar2 + 0xe) & 0x10) == 0) {
            nwk_raise_link_failure(auStack_12[0],uStack_14);
          }
          else {
            nwk_raise_mto_route_failure(auStack_12[0],uStack_14);
          }
        }
      }
      else {
        nwk_raise_source_route_failure(auStack_12[0]);
      }
    }
    if (param_1 != 0) {
      zmsg_free(param_1);
    }
  }
  return;
}

