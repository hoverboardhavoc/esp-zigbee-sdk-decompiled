/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_ed_mngr.o -> nwk_ed_handle_poll_confirm
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
  int iVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  
  iVar3 = core_globals_get();
  if (-1 < *(int *)(iVar3 + 0xb14) << 10) {
    return;
  }
  cVar1 = *param_1;
  iVar3 = core_globals_get();
  if (((*(byte *)(iVar3 + 0xaf8) & 0x40) != 0) &&
     (iVar3 = core_globals_get(), (*(byte *)(iVar3 + 0xa28) & 1) != 0)) {
    nwk_ed_process_keepalive_result(cVar1 == -0x15 || cVar1 == '\0');
  }
  iVar3 = core_globals_get();
  uVar2 = *(uint *)(iVar3 + 0xb14) >> 0x15 & 1;
  if (uVar2 == 0) {
    return;
  }
  cVar1 = *param_1;
  if (cVar1 == -0x1f) {
    iVar4 = core_globals_get();
    iVar3 = iVar4 + 0x1000;
    bVar5 = *(byte *)(iVar4 + 0xb16) | 0x10;
  }
  else if ((cVar1 == -0x15) || (cVar1 == '\0')) {
    iVar3 = core_globals_get();
    if (*(short *)(iVar3 + 0xb14) == 0) {
_L0:
      uVar2 = 0;
    }
    else {
      iVar3 = core_globals_get();
      *(short *)(iVar3 + 0xb14) = *(short *)(iVar3 + 0xb14) + -1;
      iVar3 = core_globals_get();
      if (*(short *)(iVar3 + 0xb14) != 0) goto _L0;
      iVar3 = core_globals_get();
      *(byte *)(iVar3 + 0xb16) = *(byte *)(iVar3 + 0xb16) & 0xf0;
    }
    iVar3 = core_globals_get();
    if ((*(byte *)(iVar3 + 0xb16) & 0x10) == 0) {
      if (uVar2 == 0) {
        return;
      }
      goto nwk_pim_schedule_next_poll;
    }
    iVar4 = core_globals_get();
    iVar3 = iVar4 + 0x1000;
    bVar5 = *(byte *)(iVar4 + 0xb16) & 0xef;
  }
  else {
    log_write(2,"nwk_ed_mngr.c","Failed to send data poll: 0x%02x");
    iVar3 = core_globals_get();
    uVar2 = *(uint *)(iVar3 + 0xb14);
    iVar4 = core_globals_get();
    iVar3 = iVar4 + 0x1000;
    bVar5 = *(byte *)(iVar4 + 0xb16) & 0xef | (byte)((uVar2 >> 0x14 & 1 ^ 1) << 4);
  }
  *(byte *)(iVar3 + -0x4ea) = bVar5;
nwk_pim_schedule_next_poll:
  iVar3 = core_globals_get();
  iVar7 = *(int *)(iVar3 + 0xb0c);
  iVar3 = core_globals_get();
  uVar2 = nwk_ed_get_keepalive_interval();
  iVar4 = core_globals_get();
  if (((*(byte *)(iVar4 + 0xb16) & 0x10) != 0) && (1000 < uVar2)) {
    uVar2 = 1000;
  }
  iVar4 = core_globals_get();
  if ((*(short *)(iVar4 + 0xb14) != 0) &&
     (iVar4 = core_globals_get(), *(uint *)(iVar4 + 0xb10) <= uVar2)) {
    iVar4 = core_globals_get();
    uVar2 = *(uint *)(iVar4 + 0xb10);
  }
  if (uVar2 == 0) {
    uVar2 = 10;
  }
  *(uint *)(iVar3 + 0xb0c) = uVar2;
  iVar3 = core_globals_get();
  iVar3 = milli_timer_is_running(iVar3 + 0xafc);
  if (iVar3 != 0) {
    iVar3 = core_globals_get();
    if (*(int *)(iVar3 + 0xb0c) != iVar7) {
      iVar3 = core_globals_get();
      iVar3 = milli_timer_get_fire_time(iVar3 + 0xafc);
      iVar4 = core_globals_get();
      iVar6 = *(int *)(iVar4 + 0xb0c);
      iVar4 = core_globals_get();
      milli_timer_fire_at(iVar4 + 0xafc,(iVar3 - iVar7) + iVar6);
      return;
    }
    return;
  }
  iVar3 = core_globals_get();
  iVar4 = core_globals_get();
  milli_timer_start(iVar3 + 0xafc,*(undefined4 *)(iVar4 + 0xb0c));
  return;
}

