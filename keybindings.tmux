bind-key -n M-k display-panes \; select-pane -U
bind-key -n M-j display-panes \; select-pane -D
bind-key -n M-h display-panes \; select-pane -L
bind-key -n M-l display-panes \; select-pane -R

bind-key -n M-i resize-pane -U
bind-key -n M-u resize-pane -D
bind-key -n M-y resize-pane -L
bind-key -n M-o resize-pane -R

bind-key -n M-p previous-window
bind-key -n M-n next-window

bind-key -n M-, display-panes \; split-window -h -c "#{pane_current_path}"    
bind-key -n M-/ display-panes \; split-window -v -c "#{pane_current_path}"
bind-key -n M-. new-window -c "#{pane_current_path}" \; rename-window "-"
