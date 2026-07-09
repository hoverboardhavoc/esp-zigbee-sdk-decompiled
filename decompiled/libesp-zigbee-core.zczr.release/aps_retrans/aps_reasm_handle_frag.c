/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_retrans.o -> aps_reasm_handle_frag
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_reasm_handle_frag(short *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined4 *__s;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  short sVar8;
  short sVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  undefined4 *extraout_a1;
  undefined4 *puVar14;
  byte bVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  byte bStack_32;
  byte abStack_31 [9];
  
  uVar16 = (uint)*(byte *)(param_1 + 6);
  if ((char)*(byte *)(param_1 + 6) < '\0') goto _L0;
_L0:
  do {
    do {
      param_1 = (short *)__assert_func(0,0,0,0);
      param_2 = extraout_a1;
_L0:
      if ((char)param_1[9] == '\0') {
_L0:
        if (param_2 == (undefined4 *)0x0) {
          return;
        }
        zmsg_free(param_2);
        return;
      }
      if (((*(byte *)((int)param_1 + 0x11) & 3) != 2) && ((char)param_1[9] == '\x01')) {
        aps_handle_datagram();
        return;
      }
      if ((uVar16 & 3) != 0) goto _L0;
      iVar10 = core_globals_get();
      sVar8 = *param_1;
      cVar1 = *(char *)((int)param_1 + 0xd);
      uVar16 = 0;
      while( true ) {
        uVar16 = bitmap_find_next_bit(iVar10 + 0x958,0x20,uVar16);
        uVar16 = uVar16 & 0xff;
        if (0x1f < uVar16) break;
        iVar17 = iVar10 + uVar16 * 0x28;
        if ((*(char *)(iVar17 + 0x466) == cVar1) && (*(short *)(iVar17 + 0x464) == sVar8)) {
          __s = (undefined4 *)(iVar10 + uVar16 * 0x28 + 0x458);
          goto _L0;
        }
        uVar16 = uVar16 + 1 & 0xff;
      }
      iVar10 = core_globals_get();
      iVar17 = iVar10 + 0x458;
      uVar16 = bitmap_find_first_zero_bit(iVar10 + 0x958,0x20);
      uVar4 = uVar16 & 0xff;
      if (0x1f < uVar4) goto _L0;
      uVar3 = 1 << (uVar16 & 7) & 0xff;
      uVar12 = __atomic_fetch_or_1((uVar4 >> 3) + iVar10 + 0x958,uVar3,5);
      uVar16 = 0;
    } while ((uVar3 & uVar12) != 0);
    iVar7 = uVar4 * 0x28;
    __s = (undefined4 *)(iVar17 + iVar7);
    memset(__s,0,0x28);
    iVar13 = core_globals_get();
    iVar18 = iVar7 + 0x10 + iVar17;
    uVar2 = *(undefined1 *)(iVar13 + 2);
    milli_timer_init(iVar18,aps_reasm_ent_handle_timeout,__s);
    iVar10 = iVar10 + iVar7;
    zmsg_queue_init(__s);
    *(undefined1 *)(iVar10 + 0x47c) = uVar2;
    aps_retrans_start_fast_poll();
    *(short *)(iVar10 + 0x464) = *param_1;
    *(undefined1 *)(iVar10 + 0x466) = *(undefined1 *)((int)param_1 + 0xd);
  } while (7 < (byte)(*(char *)(iVar10 + 0x47c) - 1U));
  *(undefined1 *)((int)__s + 0x21) = 0xff;
  *(undefined1 *)((int)__s + 0x22) = 0;
  aps_tx_window_reset_slots(iVar17 + iVar7 + 0x21);
  milli_timer_start(iVar18,0x640);
_L0:
  uVar16 = 0;
  if ((*(byte *)((int)param_1 + 0x11) & 3) != 1) {
    uVar16 = (uint)*(byte *)(param_1 + 9);
  }
  uVar4 = (uint)*(byte *)((int)__s + 0x22);
  bStack_32 = (byte)uVar16;
  if (uVar16 < uVar4) goto _L0;
  uVar3 = (uint)*(byte *)(__s + 9);
  if (uVar4 + uVar3 <= uVar16) {
    if ((*(char *)((int)__s + 0x25) != -1) ||
       (iVar10 = aps_tx_window_move_next((int)__s + 0x21), iVar10 == 0)) goto _L0;
    *(undefined1 *)(__s + 8) = 0;
    milli_timer_start(__s + 4,0x640);
    uVar4 = (uint)*(byte *)((int)__s + 0x22);
    uVar3 = (uint)*(byte *)(__s + 9);
    uVar16 = (uint)bStack_32;
    if (uVar16 < uVar4 + uVar3) goto _L0;
  }
  uVar12 = uVar16 - uVar4;
  uVar5 = uVar12 & 0x1f;
  if (((uVar12 & 0xff) == uVar3 - 1) ||
     (uVar16 = (1 << ((uVar3 + uVar4) - uVar16 & 0x1f)) + -1 << (uVar12 & 0x1f),
     uVar16 == (*(byte *)((int)__s + 0x25) & uVar16))) {
    aps_send_ack(param_1,param_2,(uint)*(byte *)((int)__s + 0x25) | 1 << uVar5 & 0xffU);
  }
  if (((int)(uint)*(byte *)((int)__s + 0x25) >> uVar5 & 1U) != 0) {
_L0:
    if (param_2 == (undefined4 *)0x0) {
      return;
    }
    zmsg_free(param_2);
    return;
  }
  bVar15 = *(byte *)((int)__s + 0x25) | (byte)(1 << uVar5);
  *(byte *)((int)__s + 0x25) = bVar15;
  uVar16 = (int)__s + 0x21;
  if (bStack_32 == 0) {
    if (*(char *)((int)__s + 0x22) != '\0') goto _L0;
    *(char *)((int)__s + 0x21) = (char)param_1[9];
    aps_tx_window_reset_slots(uVar16,*(undefined1 *)(__s + 9));
    *(undefined1 *)((int)__s + 0x23) = 1;
    *(byte *)((int)__s + 0x25) = bVar15 | *(byte *)((int)__s + 0x25);
  }
  for (puVar6 = (undefined4 *)*__s; __s != puVar6; puVar6 = (undefined4 *)*puVar6) {
    abStack_31[0] = 0;
    zmsg_get_footer(puVar6,abStack_31,1);
    if (bStack_32 < abStack_31[0]) break;
  }
  zmsg_add_footer(param_2,&bStack_32,1);
  puVar14 = (undefined4 *)puVar6[1];
  puVar6[1] = param_2;
  *param_2 = puVar6;
  param_2[1] = puVar14;
  *puVar14 = param_2;
  *(short *)(__s + 2) = *(short *)(__s + 2) + 1;
  puVar6 = (undefined4 *)zmsg_queue_get_head(__s);
  while (puVar14 = (undefined4 *)*puVar6, __s != puVar14) {
    abStack_31[0] = 0;
    bVar15 = *(char *)((int)__s + 0x22) + *(char *)((int)__s + 0x23);
    zmsg_get_footer(puVar14,abStack_31,1);
    if (bVar15 != abStack_31[0]) {
      if (abStack_31[0] <= bVar15) goto _L0;
      break;
    }
    *(char *)((int)__s + 0x23) = *(char *)((int)__s + 0x23) + '\x01';
    zmsg_queue_dequeue(__s,puVar14);
    uVar11 = zmsg_get_offset(puVar14);
    sVar8 = zmsg_get_length(puVar14);
    sVar9 = zmsg_get_offset(puVar14);
    iVar10 = zmsg_append_bytes_from_msg(puVar6,puVar14,uVar11,sVar8 - sVar9);
    if (iVar10 != 0) {
      log_write(1,"aps_retrans.c","Failed to merge frag queue: %d",iVar10);
    }
    zmsg_free(puVar14);
  }
  if (*(char *)((int)__s + 0x25) != -1) {
    return;
  }
  iVar10 = aps_tx_window_move_next(uVar16);
  if (iVar10 != 0) {
    return;
  }
  if (*(short *)(__s + 2) == 1) {
    uVar11 = zmsg_queue_get_head(__s);
    zmsg_queue_dequeue(__s,uVar11);
    *(undefined1 *)(__s + 8) = 3;
    milli_timer_start(__s + 4,0x640);
    aps_handle_data(param_1,uVar11);
    return;
  }
  goto _L0;
}

