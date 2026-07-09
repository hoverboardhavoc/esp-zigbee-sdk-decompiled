/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_handle_leave_sent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_leave_sent(int param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int extraout_a1;
  byte bStack_3d;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_2c;
  int iStack_28;
  code *pcStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  ushort uStack_14;
  byte abStack_11 [5];
  
  abStack_11[0] = 0;
  sVar3 = zmsg_get_offset();
  zmsg_read_bytes(param_1,sVar3 + 1,1,abStack_11);
  if ((abStack_11[0] & 0x40) != 0) {
    if (param_2 == 0x1f0) {
      param_2 = 0;
    }
    uStack_1c = 0;
    uStack_18 = 0;
    local_20 = param_2 & 0xff;
    uStack_14 = (ushort)(byte)((byte)((abStack_11[0] & 1) << 1) | abStack_11[0] >> 5 & 1);
    iVar4 = nwk_frame_get_dst_extaddr(param_1,&uStack_1c);
    if (iVar4 == 0) {
      zmsg_read_bytes(param_1,2,(int)&local_20 + 2);
      nwk_handle_device_leave((int)&local_20 + 2);
      nwk_leave_confirm(&local_20);
    }
_L0:
    if (param_1 != 0) {
      zmsg_free(param_1);
    }
    return;
  }
  iVar4 = core_globals_get();
  if (*(char *)(iVar4 + 0xac0) == '\x04') {
    nwk_do_leave_continue(0,abStack_11[0] >> 5 & 1,abStack_11[0] >> 7);
    goto _L0;
  }
  pcVar2 = nwk_handle_leave;
  iVar4 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_nlme.c",0x252,
                        "nwk_handle_leave_sent",
                        "(((*core_globals_get()).nwk).ctx).state == NWK_STATE_LEAVING");
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_3c = (uint)*(ushort *)(extraout_a1 + 6);
  bStack_3d = 0;
  uStack_2c = param_2;
  iStack_28 = param_1;
  pcStack_24 = pcVar2;
  iVar5 = nwk_is_joined();
  if ((iVar5 != 0) && (*(short *)(extraout_a1 + 2) == *(short *)(extraout_a1 + 6))) {
    iVar5 = nwk_secur_get_seclevel();
    if (((*(ushort *)(iVar4 + 0x16) & 2) != 0) != (iVar5 != 0)) goto _L0;
    iVar5 = nwk_frame_get_src_extaddr(iVar4,(int)&uStack_3c + 2);
    if ((iVar5 == 0) ||
       (iVar5 = nwk_address_extended_by_short(*(undefined2 *)(extraout_a1 + 6),(int)&uStack_3c + 2),
       iVar5 == 0)) {
      sVar3 = zmsg_get_offset(iVar4);
      zmsg_read_bytes(iVar4,sVar3 + 1,1,&bStack_3d);
      uVar1 = uStack_34 >> 0x10;
      uStack_34._0_3_ =
           CONCAT12((byte)uVar1 & 0xfc | bStack_3d >> 5 & 1 | (bStack_3d >> 7) << 1,
                    (undefined2)uStack_34);
      if ((bStack_3d & 0x40) == 0) {
        nwk_handle_device_leave(&uStack_3c);
        nwk_leave_indication(&uStack_3c);
      }
      else {
        iVar5 = nwk_validate_leave_request
                          (*(undefined2 *)(extraout_a1 + 6),*(undefined2 *)(extraout_a1 + 4));
        if (((iVar5 != 0) && (iVar5 = core_globals_get(), *(char *)(iVar5 + 0xac0) != '\x04')) &&
           (iVar5 = core_globals_get(), *(char *)(iVar5 + 0xac0) == '\0')) {
          nwk_do_leave(1,uStack_34 >> 0x10 & 1,uStack_34 >> 0x11 & 1);
        }
      }
    }
  }
  if (iVar4 == 0) {
    return;
  }
_L0:
  zmsg_free(iVar4);
  return;
}

