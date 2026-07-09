/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_ed_handle_poll_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_ed_handle_poll_confirm(char *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = core_globals_get();
  if ((*(uint *)(iVar3 + 0xb14) >> 0x15 & 1) != 0) {
    if (*param_1 == '\0') {
      uVar4 = 1;
    }
    else if (*param_1 == -0x15) {
      uVar4 = 1;
    }
    else {
      uVar4 = 0;
    }
    iVar3 = core_globals_get();
    if (((*(byte *)(iVar3 + 0xaf8) & 0x40) != 0) &&
       (iVar3 = core_globals_get(), (*(byte *)(iVar3 + 0xa28) & 1) != 0)) {
      nwk_ed_process_keepalive_result(uVar4);
    }
    iVar3 = core_globals_get();
    uVar2 = *(uint *)(iVar3 + 0xb14) >> 0x15 & 1;
    if (uVar2 != 0) {
      cVar1 = *param_1;
      if (cVar1 == -0x1f) {
        iVar3 = core_globals_get();
        *(byte *)(iVar3 + 0xb16) = *(byte *)(iVar3 + 0xb16) | 0x10;
      }
      else if ((cVar1 == -0x15) || (cVar1 == '\0')) {
        iVar3 = core_globals_get();
        if (*(short *)(iVar3 + 0xb14) == 0) {
          uVar2 = 0;
        }
        else {
          iVar3 = core_globals_get();
          *(short *)(iVar3 + 0xb14) = *(short *)(iVar3 + 0xb14) + -1;
          iVar3 = core_globals_get();
          if (*(short *)(iVar3 + 0xb14) == 0) {
            iVar3 = core_globals_get();
            *(byte *)(iVar3 + 0xb16) = *(byte *)(iVar3 + 0xb16) & 0xf0;
          }
          else {
            uVar2 = 0;
          }
        }
        iVar3 = core_globals_get();
        if ((*(byte *)(iVar3 + 0xb16) & 0x10) == 0) {
          if (uVar2 == 0) {
            return;
          }
        }
        else {
          iVar3 = core_globals_get();
          *(byte *)(iVar3 + 0xb16) = *(byte *)(iVar3 + 0xb16) & 0xef;
        }
      }
      else {
        log_write(2,"nwk_ed_mngr.c","Failed to send data poll: 0x%02x");
        iVar3 = core_globals_get();
        uVar2 = *(uint *)(iVar3 + 0xb14);
        iVar3 = core_globals_get();
        *(byte *)(iVar3 + 0xb16) =
             *(byte *)(iVar3 + 0xb16) & 0xef | (byte)((uVar2 >> 0x14 & 1 ^ 1) << 4);
      }
      nwk_pim_schedule_next_poll(1);
    }
  }
  return;
}

