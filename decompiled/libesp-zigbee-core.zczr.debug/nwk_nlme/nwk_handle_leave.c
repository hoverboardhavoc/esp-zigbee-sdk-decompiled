/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_handle_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_leave(int param_1,int param_2)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  byte bStack_1d;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_1c = (uint)*(ushort *)(param_2 + 6);
  bStack_1d = 0;
  iVar3 = nwk_is_joined();
  if ((iVar3 != 0) && (*(short *)(param_2 + 2) == *(short *)(param_2 + 6))) {
    iVar3 = nwk_secur_get_seclevel();
    if (((*(ushort *)(param_1 + 0x16) & 2) != 0) != (iVar3 != 0)) goto _L0;
    iVar3 = nwk_frame_get_src_extaddr(param_1,(int)&uStack_1c + 2);
    if ((iVar3 == 0) ||
       (iVar3 = nwk_address_extended_by_short(*(undefined2 *)(param_2 + 6),(int)&uStack_1c + 2),
       iVar3 == 0)) {
      sVar2 = zmsg_get_offset(param_1);
      zmsg_read_bytes(param_1,sVar2 + 1,1,&bStack_1d);
      uVar1 = uStack_14 >> 0x10;
      uStack_14._0_3_ =
           CONCAT12((byte)uVar1 & 0xfc | bStack_1d >> 5 & 1 | (bStack_1d >> 7) << 1,
                    (undefined2)uStack_14);
      if ((bStack_1d & 0x40) == 0) {
        nwk_handle_device_leave(&uStack_1c);
        nwk_leave_indication(&uStack_1c);
      }
      else {
        iVar3 = nwk_validate_leave_request
                          (*(undefined2 *)(param_2 + 6),*(undefined2 *)(param_2 + 4));
        if (((iVar3 != 0) && (iVar3 = core_globals_get(), *(char *)(iVar3 + 0xac0) != '\x04')) &&
           (iVar3 = core_globals_get(), *(char *)(iVar3 + 0xac0) == '\0')) {
          nwk_do_leave(1,uStack_14 >> 0x10 & 1,uStack_14 >> 0x11 & 1);
        }
      }
    }
  }
  if (param_1 == 0) {
    return;
  }
_L0:
  zmsg_free(param_1);
  return;
}

