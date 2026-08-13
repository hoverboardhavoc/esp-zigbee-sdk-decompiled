/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_cli.o -> nwk_handle_network_comm_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_network_comm_rsp(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  ushort uVar5;
  undefined2 uStack_34;
  byte bStack_32;
  undefined1 auStack_30 [8];
  int iStack_28;
  int iStack_24;
  
  iVar2 = nwk_is_joined();
  if ((iVar2 != 0) || (iVar2 = core_globals_get(), *(char *)(iVar2 + 0xac0) == '\x02')) {
    iVar2 = nwk_secur_get_seclevel();
    uVar5 = (ushort)(iVar2 != 0);
    iVar2 = core_globals_get();
    if (*(char *)(iVar2 + 0xac0) == '\x02') {
      iVar2 = core_globals_get();
      uVar5 = *(ushort *)(iVar2 + 0xad2) & 1;
    }
    if (*(short *)(param_2 + 2) == *(short *)(param_2 + 6)) {
      if ((uVar5 == (*(ushort *)(param_1 + 0x16) >> 1 & 1)) &&
         (iVar2 = nwk_frame_get_src_extaddr(param_1,auStack_30), iVar2 == 0)) {
        iVar2 = nwk_frame_get_dst_extaddr(param_1,&iStack_28);
        if (iVar2 == 0) {
          piVar4 = (int *)nwk_get_extended_address();
          if ((iStack_28 != *piVar4) || (iStack_24 != piVar4[1])) goto _L0;
        }
        uVar5 = *(ushort *)(param_2 + 6);
        uVar3 = nwk_get_parent_shortaddr();
        if (uVar5 == uVar3) {
          uStack_34 = 0;
          bStack_32 = 0;
          sVar1 = zmsg_get_offset(param_1);
          zmsg_read_bytes(param_1,sVar1 + 1,3,&uStack_34);
          iVar2 = core_globals_get();
          if (*(char *)(iVar2 + 0xac0) == '\0') {
            iVar2 = nwk_is_device_zed();
            if ((iVar2 != 0) && (iVar2 = nwk_is_joined(), iVar2 != 0)) {
              nwk_change_network_address(uStack_34);
            }
          }
          else if (*(char *)(iVar2 + 0xac0) == '\x02') {
            iVar2 = core_globals_get();
            milli_timer_stop(iVar2 + 0xad4);
            iVar2 = core_globals_get();
            if (*(char *)(iVar2 + 0x9ee) == '\0') {
              nwk_pim_stop_fast_poll();
              nwk_pim_stop_poll();
            }
            if (bStack_32 == 0) {
              nwk_mm_set_pib_attr(*(undefined1 *)(param_2 + 8),0x4a,auStack_30);
            }
            uVar3 = 0;
            if (bStack_32 != 0) {
              uVar3 = bStack_32 | 0x200;
            }
            nwk_do_attach_done(uVar3,uStack_34);
          }
        }
      }
      goto _L0;
    }
  }
  if (param_1 == 0) {
    return;
  }
_L0:
  zmsg_free(param_1);
  return;
}

