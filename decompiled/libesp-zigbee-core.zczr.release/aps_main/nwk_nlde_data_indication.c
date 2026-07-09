/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> nwk_nlde_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_nlde_data_indication(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uStack_24;
  uint uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uVar2 = param_1[2];
  iVar3 = aps_frame_validate_nsdu(uVar2);
  if (iVar3 != 0) {
    uStack_24 = 0;
    uStack_20 = 0;
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_14 = 0;
    iVar3 = aps_frame_parse_hdr(uVar2,&uStack_24);
    uVar1 = uStack_18;
    if (iVar3 == 0) {
      uStack_24 = *param_1;
      uStack_18 = CONCAT13((char)param_1[1],(uint3)uStack_18);
      uStack_14 = CONCAT31(uStack_14._1_3_,*(undefined1 *)((int)param_1 + 5));
      if ((((uVar1 & 0xc) != 0xc) || (iVar3 = aps_group_table_find(uStack_20 & 0xffff), iVar3 != 0))
         && (iVar3 = aps_process_receive_security(uStack_24 & 0xffff,uVar2), iVar3 == 0)) {
        if ((uStack_18 & 3) == 1) {
          uVar4 = zmsg_get_offset(uVar2);
          zmsg_read_bytes(uVar2,uVar4,1,(int)&uStack_18 + 2);
        }
        else {
          uStack_18._0_3_ = (uint3)(ushort)uStack_18;
        }
        if (((char)uStack_18 < '\0') && ((uStack_18 & 3) != 2)) {
          aps_reasm_handle_frag(&uStack_24,uVar2);
          return;
        }
        aps_handle_datagram(&uStack_24,uVar2);
        return;
      }
    }
  }
  if (uVar2 != 0) {
    zmsg_free(uVar2);
  }
  return;
}

