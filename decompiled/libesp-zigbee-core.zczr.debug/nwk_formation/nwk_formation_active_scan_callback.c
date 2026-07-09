/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_formation.o -> nwk_formation_active_scan_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_formation_active_scan_callback(int param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  byte bStack_16;
  byte bStack_15;
  byte bStack_14;
  
  iVar2 = core_globals_get();
  if (param_1 != 0) {
    nwk_disc_table_lite_add_pan(param_1 + 4);
    *(uint *)(iVar2 + 0xac8) =
         *(uint *)(iVar2 + 0xac8) & 0xf8000000 |
         *(uint *)(iVar2 + 0xac8) & 0x7ffffff & ~(1 << (*(byte *)(param_1 + 0x11) & 0x1f));
    return;
  }
  pbVar3 = (byte *)nwk_disc_table_lite_finish();
  if ((*(uint *)(iVar2 + 0xac8) & 0x7ffffff) == 0) {
_L0:
    nwk_get_panid();
    iVar2 = nwk_check_assigned_panid();
    if (iVar2 == 0) goto _L0;
  }
  else {
    *pbVar3 = (byte)((uint)*(undefined4 *)(iVar2 + 0xac8) >> 0x1b);
    pbVar3[1] = 0xff;
    iVar2 = channel_page_get_next_channel(*(undefined4 *)(iVar2 + 0xac8),pbVar3 + 1);
    if (iVar2 == 0) {
      pbVar3[2] = 0;
      goto _L0;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_formation.c",0xd4,
                  "nwk_formation_active_scan_callback",
                  "(channel_page_get_next_channel(form->scan_channels, &disc_lite->channel_number)) == 0"
                 );
_L0:
    nwk_assign_panid();
    nwk_set_panid();
  }
  iVar2 = nwk_is_device_zc();
  if (iVar2 == 0) {
    uVar7 = nwk_get_short_address();
    if ((0xfff7 < uVar7) || (iVar2 = nwk_get_short_address(), iVar2 == 0)) {
      nwk_assign_shortaddr();
      nwk_set_short_address();
    }
  }
  else {
    nwk_set_short_address(0);
  }
  uVar4 = nwk_get_extended_address();
  uVar5 = nwk_get_short_address();
  iVar2 = nwk_address_update(uVar4,uVar5,&uStack_1a);
  if (iVar2 == 0) {
    nwk_address_lock_ref(uStack_1a);
    piVar6 = (int *)nwk_get_extended_panid();
    if ((*piVar6 == 0 && piVar6[1] == 0) || ((*piVar6 == -1 && (piVar6[1] == -1)))) {
      nwk_get_extended_address();
      nwk_set_extended_panid();
    }
    uStack_18 = nwk_get_panid();
    bStack_16 = pbVar3[1];
    bStack_15 = *pbVar3;
    bVar1 = nwk_is_device_zc();
    bStack_14 = bStack_14 & 0xfe | bVar1 & 1;
    iVar2 = nwk_mm_start_request(0,&uStack_18);
    if (iVar2 == 0) {
      iVar2 = core_globals_get();
      *(byte *)(iVar2 + 0xb18) = *(byte *)(iVar2 + 0xb18) | 1;
      uVar4 = 0;
      goto _L0;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_formation.c",0xe8,
                  "nwk_formation_active_scan_callback",
                  "(nwk_address_update(nwk_get_extended_address(), nwk_get_short_address(), &ref)) == 0"
                 );
  }
  iVar2 = core_globals_get();
  *(byte *)(iVar2 + 0xb18) = *(byte *)(iVar2 + 0xb18) & 0xfe;
  uVar4 = 0xc4;
_L0:
  iVar2 = core_globals_get();
  *(undefined1 *)(iVar2 + 0xac0) = 0;
  nwk_network_formation_confirm(uVar4);
  return;
}

