/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_retrans.o -> aps_retrans_handle_ack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_retrans_handle_ack(short *param_1,undefined4 param_2)

{
  char cVar1;
  short sVar2;
  int iVar3;
  undefined4 extraout_a1;
  uint uVar4;
  int iVar5;
  byte bVar6;
  
  if ((*(byte *)(param_1 + 6) & 3) != 2) {
    param_1 = (short *)__assert_func(0,0,0,0);
    param_2 = extraout_a1;
  }
  iVar3 = core_globals_get();
  sVar2 = *param_1;
  cVar1 = *(char *)((int)param_1 + 0xd);
  uVar4 = 0;
  do {
    uVar4 = bitmap_find_next_bit(iVar3 + 0x454,0x20,uVar4);
    uVar4 = uVar4 & 0xff;
    if (0x1f < uVar4) {
_L0:
      zmsg_free(param_2);
      return;
    }
    iVar5 = iVar3 + uVar4 * 0x20;
    if ((*(char *)(iVar5 + 0x5a) == cVar1) && (*(short *)(iVar5 + 0x58) == sVar2)) {
      iVar3 = iVar3 + uVar4 * 0x20 + 0x54;
      bVar6 = ~*(byte *)(iVar3 + 0x1e);
      if (((char)param_1[6] < '\0') && ((byte)((*(byte *)((int)param_1 + 0x11) & 3) - 1) < 2)) {
        if (*(char *)(iVar3 + 0x1b) == (char)param_1[9]) {
          bVar6 = bVar6 & *(byte *)((int)param_1 + 0x13);
        }
      }
      else if ((*(uint *)(iVar3 + 0x18) & 0xffff0000) == 0x10000) {
        bVar6 = bVar6 & 1;
      }
      if (bVar6 != 0) {
        *(undefined1 *)(iVar3 + 0x18) = 1;
        *(byte *)(iVar3 + 0x1e) = *(byte *)(iVar3 + 0x1e) | bVar6;
        if (*(char *)(iVar3 + 0x1c) == '\0') {
          milli_timer_stop();
          milli_timer_start(iVar3 + 8,0x640);
        }
      }
      if (*(char *)(iVar3 + 0x1e) == -1) {
        milli_timer_stop(iVar3 + 8);
        iVar5 = aps_tx_window_move_next(iVar3 + 0x1a);
        if (iVar5 == 0) {
          aps_retrans_send_confirm(iVar3,0);
        }
        else {
          *(undefined1 *)(iVar3 + 0x18) = 0;
          aps_retrans_send(iVar3);
        }
      }
      goto _L0;
    }
    uVar4 = uVar4 + 1 & 0xff;
  } while( true );
}

